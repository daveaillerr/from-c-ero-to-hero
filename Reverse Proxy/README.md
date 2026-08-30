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
| 1 | [Core Source](#core-source) | Winsock initialization, connection multiplexing, select, cross-platform networking | 1 |

---

## Core Source

> Path: [`/src`](./src/)

Contains the socket programming logic for Windows and cross-platform networking.

| Project | Description |
|---------|--------------|
| `windows.c` | Winsock2 server setup, socket binding, backend connection handshake, and bidirectional I/O multiplexing with `select()` |

### Architectural Flow

The Windows implementation (`windows.c`) executes the following operations:
1. **Winsock Startup**: Calls `WSAStartup` to load the Windows Sockets DLL.
2. **Port Binding**: Binds to port `3094` using the resolved address from `getaddrinfo`.
3. **Connection Acceptance**: Enters a loop to accept incoming client connections.
4. **Backend Connection**: Resolves and connects to the backend host (`127.0.0.1:8080`).
5. **I/O Multiplexing**: Sets up an `fd_set` and monitors both client and backend sockets using `select()` to forward TCP traffic bidirectionally.

### Future Improvements

- [x] Complete backend connection establishment (`connect` logic)
- [x] Implement robust disconnection and timeout handling
- [ ] Add support for multiple concurrent client connections

---

## Tools and Requirements

| Tool | Version | Purpose |
|------|---------|---------|
| [GCC](https://gcc.gnu.org/) | C99 or later | C compiler for compilation |
| Windows OS / Linux OS | Any modern version | Target platforms for execution |

---

## Getting Started

1. Clone this repository and navigate to the directory:
   ```bash
   git clone https://github.com/USERNAME/REPO.git
   cd "Reverse Proxy"
   ```
2. Compile on Windows using GCC with Winsock library linked:
   ```bash
   gcc src/windows.c -o src/windows.exe -lws2_32
   ```
3. Run the compiled proxy server:
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

