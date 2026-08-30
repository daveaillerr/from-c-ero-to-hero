<div align="center">

# C Programming: From Zero to Hero

**Comprehensive C Programming Repository: Core Concepts, Systems Projects, and Applications**
An organized collection of C programming projects ranging from fundamental language constructs to systems networking and terminal software.

[![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c)
[![Compiler](https://img.shields.io/badge/Compiler-GCC-00599C?style=for-the-badge&logo=gnu&logoColor=white)](https://gcc.gnu.org/)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](https://opensource.org/licenses/MIT)

</div>

---

> Master C programming from core syntax and memory management to network socket proxies, terminal UI tools, and image processing applications.

---

| # | Category | Topics Covered | Files |
|---|----------|-----------------|-------|
| 1 | [Basics](#basics) | Control flow, arrays, pointers, strings, functions, structures, linked lists, file handling | 49 |
| 2 | [Reverse Proxy](#reverse-proxy) | Winsock initialization, socket binding, TCP connection relay, select I/O multiplexing | 1 |
| 3 | [ASCII Art in C](#ascii-art-in-c) | Image loading (stb_image), downsampling (stb_image_resize2), character intensity mapping | 1 |
| 4 | [PasGenCheck](#pasgencheck) | Random password generation, security rules evaluation, Win32 console coloring, typewriter animation | 1 |

---

## Basics

> Path: [`/Basics`](./Basics/)

Fundamental C language exercises organized into 10 structured core modules.

| Project | Description |
|---------|--------------|
| `Applications` | Terminal utility applications (bank manager, calculator, mobile plan) |
| `Arrays` | Array initialization, traversal, element copying, duplicate detection |
| `Conditional Constructs` | Branching logic, ATM withdrawal simulation, POS cashier checkout |
| `File Handling` | Persistent disk file append, expense tracker logging, conditional file reading |
| `Functions` | Parameter passing, binary conversion, ASCII codes, geometry calculations |
| `Linked Lists` | Dynamic memory allocation, node insertion, middle element search, student database |
| `Loops` | Matrix iteration, pyramid pattern rendering, loop control structures |
| `Pointers` | Raw memory address arithmetic, dereferencing, function pointers, array offsets |
| `Strings` | Null-terminated string routines (concat, reverse, compare, length, truncate) |
| `Structures` | Custom composite data structures (`struct`) for real-world record models |

---

## Reverse Proxy

> Path: [`/Reverse Proxy`](./Reverse%20Proxy/)

A TCP reverse proxy built in C demonstrating socket programming and I/O multiplexing.

| Project | Description |
|---------|--------------|
| `windows.c` | Winsock2 server implementation forwarding TCP traffic bidirectionally using `select()` |

---

## ASCII Art in C

> Path: [`/ASCII Art in C`](./ASCII%20Art%20in%20C/)

A console utility converting standard image formats into terminal ASCII art.

| Project | Description |
|---------|--------------|
| `main.c` | Image loading, downsampling, aspect ratio calculation, and character density printing |

---

## PasGenCheck

> Path: [`/PasGenCheck`](./PasGenCheck/)

An interactive terminal tool for generating random passwords and evaluating password strength.

| Project | Description |
|---------|--------------|
| `main.c` | Win32 Console API interface, function pointer rule array, and time-seeded generator |

---

## Tools and Requirements

| Tool | Version | Purpose |
|------|---------|---------|
| [GCC](https://gcc.gnu.org/) | C99 or later | Primary C compiler for code execution |
| [GNU Make](https://www.gnu.org/software/make/) | 3.81 or later | Build automation for multi-file projects |
| Windows OS | Windows 7 or later | Required environment for Winsock and Win32 Console API modules |

---

## Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/USERNAME/c-programming-from-zero-to-hero.git
   cd c-programming-from-zero-to-hero
   ```
2. Navigate to any project module of interest:
   ```bash
   cd "ASCII Art in C"
   ```
3. Build and execute according to the project's specific `README.md` instructions.

---

## License

This project is licensed under the [MIT License](LICENSE).

---

<div align="center">

Built with C.

Star this repository if it was useful.

</div>
