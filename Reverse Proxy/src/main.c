#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h> // Required for Windows
#include <ws2tcpip.h> // Additional socket functions

#define PORT "3094"

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
        closesocket();
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
        printf("Error");
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
            printf("error: setsockopt");
            exit(1);
        }


    // Bind

        if (bind(socketfd, p->ai_addr, p->ai_addrlen) == SOCKET_ERROR){
            closesocket(socketfd);
            printf("server: bind");
            continue;
        }
        
        break;
    }

    freeaddrinfo(serverinfo); // all done with the struct

    if (p == NULL)  {
        fprintf(stderr, "server: failed to bind\n");
        exit(1);
    }

    // Listen

    if (listen(socketfd, 5) < 0){
        fprintf(stderr, "server: listen failed - %d\n", WSAGetLastError());
        closesocket(socketfd);
        WSACleanup();
        exit(1);
    }

    printf("Waiting for connection...");
    
    // Set-up

    sin_size = sizeof their_addr;
    fd_set readfds;
    struct timeval tv;
    
    // Set-up select()
    
    tv.tv_sec = 10; // wait timeout
    char newfd_buff[4090], backendfd_buff[4090];
    int n = backendfd + 1;
    
    // Accept

    while(1) {
   

        newfd = accept(socketfd, (struct sockaddr *)&their_addr, &sin_size);
        backendfd = socket(p->ai_family, p->ai_socktype,p->ai_protocol);
        connect_backendfd = connect();  

        if (newfd == INVALID_SOCKET) {
            fprintf(stderr,"server: accept failed");
            continue;
        }   
        
        // To make it readable string

        inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr), s, sizeof s);  
        printf("\nserver got a connection from %s\n", s);
        
        // Clear set
        FD_ZERO(&readfds);

        // Set-up sockets we need (Client <-> Proxy <-> Server)
        FD_SET(newfd, &readfds);
        FD_SET(backendfd, &readfds);



        while (1){
            int activity = select(n, &readfds, NULL, NULL, &tv); 
        
            if (activity == SOCKET_ERROR){
                printf("SOCKET ERROR");
            }
            else if (activity == 0){
                printf("select() timeout");
            }
            else {
                if (FD_ISSET(newfd, &readfds)){
                    int newfd_rcv = recv(newfd, newfd_buff, sizeof newfd_buff, 0);
        
                }
                if (FD_ISSET(backendfd, &readfds)){
                    int backendfd_rcv = recv(backendfd, backendfd_buff, sizeof backendfd_buff, 0);

                }
            }       
        }
        


    }

    // Close socket

    return 0;
}