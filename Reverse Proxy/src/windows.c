#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h> // Required for Windows
#include <ws2tcpip.h> // Additional socket functions

#define PORT "3094"
#define BACKEND_HOST "[IP_ADDRESS]"
#define BACKEND_PORT "8080"

void *get_in_addr(struct sockaddr *sa){
    if (sa->sa_family == AF_INET){
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(void) {
    // 1. Declare the structure
    WSADATA wsaData;

    // 2. Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed.\n");
        exit(1);
    }

    // 3. Version Check
    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
        fprintf(stderr, "Version 2.2 of Winsock not available.\n");
        WSACleanup(); // Clean up if version check fails
        exit(2);
    }

    printf("Winsock initialized successfully!\n");

    // Reverse Proxy Program

    SOCKET socketfd, newfd, backendfd; 
    struct addrinfo hints, *serverinfo, *p;  
    struct sockaddr_storage their_addr; // connector's address info
    char s[INET6_ADDRSTRLEN];
    socklen_t sin_size;
    int status;
    int yes = 1;

    // Clean up struct before use
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // Get address info for DNS-like resolution

    if ((status = getaddrinfo(NULL, PORT, &hints, &serverinfo)) != 0){
        printf("Error getting address info: %d\n", status);
        WSACleanup();
        return 1;
    }

    // Socket   

    for (p = serverinfo; p != NULL; p = p->ai_next){
        if ((socketfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == INVALID_SOCKET){
            printf("socket failed: %d\n", WSAGetLastError());
            continue;
        }

        // setsockopt for preventing "address already in use"  
        if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, (const char *)&yes, sizeof(int)) < 0){
            printf("error: setsockopt\n");
            closesocket(socketfd);
            freeaddrinfo(serverinfo);
            WSACleanup();
            exit(1);
        }

        // Bind

        if (bind(socketfd, p->ai_addr, (int)p->ai_addrlen) == SOCKET_ERROR){
            closesocket(socketfd);
            printf("server: bind\n");
            continue;
        }
        
        break;
    }

    freeaddrinfo(serverinfo); // all done with the struct

    if (p == NULL)  {
        fprintf(stderr, "server: failed to bind\n");
        WSACleanup();
        exit(1);
    }

    // Listen

    if (listen(socketfd, 5) < 0){
        fprintf(stderr, "server: listen failed - %d\n", WSAGetLastError());
        closesocket(socketfd);
        WSACleanup();
        exit(1);
    }

    printf("Waiting for connection on port %s...\n", PORT);
    
    // Set-up

    sin_size = sizeof their_addr;
    fd_set readfds;
    struct timeval tv;
    char newfd_buff[4096], backendfd_buff[4096];
    
    // Accept loop

    while(1) {
        newfd = accept(socketfd, (struct sockaddr *)&their_addr, &sin_size);
        if (newfd == INVALID_SOCKET) {
            fprintf(stderr,"server: accept failed - %d\n", WSAGetLastError());
            continue;
        }   
        
        // To make it readable string

        inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr), s, sizeof s);  
        printf("\nserver got a connection from %s\n", s);
        
        // Connect to backend server

        struct addrinfo backend_hints, *backendinfo;
        memset(&backend_hints, 0, sizeof(backend_hints));
        backend_hints.ai_family = AF_INET;
        backend_hints.ai_socktype = SOCK_STREAM;

        if (getaddrinfo(BACKEND_HOST, BACKEND_PORT, &backend_hints, &backendinfo) != 0) {
            fprintf(stderr, "Failed to resolve backend address\n");
            closesocket(newfd);
            continue;
        }

        backendfd = socket(backendinfo->ai_family, backendinfo->ai_socktype, backendinfo->ai_protocol);
        if (backendfd == INVALID_SOCKET) {
            fprintf(stderr, "Backend socket creation failed: %d\n", WSAGetLastError());
            freeaddrinfo(backendinfo);
            closesocket(newfd);
            continue;
        }

        if (connect(backendfd, backendinfo->ai_addr, (int)backendinfo->ai_addrlen) == SOCKET_ERROR) {
            fprintf(stderr, "Connecting to backend failed: %d\n", WSAGetLastError());
            freeaddrinfo(backendinfo);
            closesocket(backendfd);
            closesocket(newfd);
            continue;
        }
        freeaddrinfo(backendinfo);
        printf("Connected to backend server (%s:%s)\n", BACKEND_HOST, BACKEND_PORT);

        // Data transfer loop (Client <-> Proxy <-> Server)

        while (1){
            // Reset set & timeout each iteration
            FD_ZERO(&readfds);
            FD_SET(newfd, &readfds);
            FD_SET(backendfd, &readfds);

            tv.tv_sec = 10;
            tv.tv_usec = 0;

            int activity = select(0, &readfds, NULL, NULL, &tv); 
        
            if (activity == SOCKET_ERROR){
                printf("SOCKET ERROR: %d\n", WSAGetLastError());
                break;
            }
            else if (activity == 0){
                // Timeout, loop again
                continue;
            }
            else {
                // Client -> Proxy -> Backend
                if (FD_ISSET(newfd, &readfds)){
                    int bytes_rcv = recv(newfd, newfd_buff, sizeof newfd_buff, 0);
                    if (bytes_rcv <= 0) {
                        printf("Client disconnected.\n");
                        break;
                    }
                    send(backendfd, newfd_buff, bytes_rcv, 0);
                }

                // Backend -> Proxy -> Client
                if (FD_ISSET(backendfd, &readfds)){
                    int bytes_rcv = recv(backendfd, backendfd_buff, sizeof backendfd_buff, 0);
                    if (bytes_rcv <= 0) {
                        printf("Backend disconnected.\n");
                        break;
                    }
                    send(newfd, backendfd_buff, bytes_rcv, 0);
                }
            }       
        }
        
        // Cleanup client & backend sockets for this connection

        closesocket(newfd);
        closesocket(backendfd);
    }

    // Close server socket & cleanup Winsock

    closesocket(socketfd);
    WSACleanup();

    return 0;
}
