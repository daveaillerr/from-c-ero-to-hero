<div align="center">

# Reverse Proxy in C

**Cross-platform TCP reverse proxy implementation in C**
Demonstrates socket programming, Winsock initialization, and connection multiplexing.

[![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-4d4d4d?style=for-the-badge)](https://en.wikipedia.org/wiki/Cross-platform)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](https://opensource.org/licenses/MIT)

</div>

---

> A lightweight, cross-platform reverse proxy prototype in C, utilizing platform-specific socket interfaces (Winsock2 for Windows, POSIX sockets for Linux) and select-based I/O multiplexing.

---

| # | Category | Topics Covered | Files |
|---|----------|-----------------|-------|
| 1 | [Core Source](#core-source) | Winsock initialization, connection multiplexing, select, cross-platform networking | 2 |

---

## Core Source

> Path: [`/src`](./src/)

Contains the socket programming logic for both Windows and Linux environments.

| Project | Description |
|---------|--------------|
| `windows.c` | Winsock2 server setup, socket binding, connection acceptance, and I/O multiplexing with `select()` |
| `linux.c` | Basic POSIX socket creation skeleton for Linux systems |

### Architectural Flow

The Windows implementation (`windows.c`) executes the following operations:
1. **Winsock Startup**: Calls `WSAStartup` to load the Windows Sockets DLL.
2. **Port Binding**: Binds to port `3094` using the resolved address from `getaddrinfo`.
3. **Connection Acceptance**: Enters a loop to accept incoming client connections.
4. **I/O Multiplexing**: Sets up an `fd_set` and monitors both client and backend server sockets using the `select` function to forward traffic bidirectionally.

### Known Limitations

- The backend connection establishment (`connect_backendfd = connect();`) is currently incomplete and holds placeholder code.
- Winsock dependencies make `windows.c` non-portable to Linux; `linux.c` is currently just a socket creation skeleton.
- Multiplexing is currently limited to a single active client-backend pair per select loop.

### Future Improvements

- [ ] Complete the backend connection establishment (`connect_backendfd` logic).
- [ ] Implement robust error handling for connection loss or timeouts.
- [ ] Standardize the codebase to use cross-platform abstraction layers (e.g., matching POSIX sockets).
- [ ] Add support for multiple concurrent client connections.

---

## Tools and Requirements

| Tool | Version | Purpose |
|------|---------|---------|
| [GCC](https://gcc.gnu.org/) | C99 or later | C compiler for compilation |
| Windows OS / Linux OS | Any modern version | Target platforms for execution |

---

## Concepts Practiced

```
Winsock API         ████████████████████  WSAStartup, socket creation, and socket options
I/O Multiplexing    ███████████████░░░░░  Socket monitoring and routing using select()
TCP Handshake       ████████████████████  Binding, listening, and accepting client connections
Cross-Platform      ██████████░░░░░░░░░░  Handling Win32 vs POSIX socket implementations
```

---

## Repository Structure

```
Reverse Proxy/
├── src/
│   ├── linux.c
│   ├── windows.c
│   └── windows.exe
└── README.md  ← current file
```

---

## Getting Started

1. Clone this repository and navigate to the directory
   ```bash
   git clone https://github.com/USERNAME/REPO.git
   cd "Reverse Proxy"
   ```
2. Compile on Windows using GCC:
   ```bash
   gcc src/windows.c -o src/windows.exe -lws2_32
   ```
3. Compile on Linux using GCC:
   ```bash
   gcc src/linux.c -o src/linux
   ```
4. Run the compiled proxy server:
   ```bash
   ./src/windows.exe
   ```

---

## License

This project is licensed under the [MIT License](LICENSE).

---

<div align="center">

Built with C socket API.

Star this repository if it was useful.

</div>
