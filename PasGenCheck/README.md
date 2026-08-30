<div align="center">

# PasGenCheck

**Password Generator & Checker**
Interactive console application for generating cryptographically random passwords and checking strength.

[![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c)
[![Build](https://img.shields.io/badge/Build-GNU%20Make-000000?style=for-the-badge&logo=gnu-make&logoColor=white)](https://www.gnu.org/software/make/)
[![Platform](https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)](https://en.wikipedia.org/wiki/Microsoft_Windows)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](https://opensource.org/licenses/MIT)

</div>

---

> An interactive, color-coded console application written in C for generating cryptographically random passwords and checking the strength of existing ones. Features an animated terminal UI built with the Windows Console API.

---

| # | Category | Topics Covered | Files |
|---|----------|-----------------|-------|
| 1 | [Core Source](#core-source) | Interactive UI, password generation, strength rules, console coloring | 1 |
| 2 | [Build Configuration](#build-configuration) | GNU Make compilation and environment tasks | 1 |

---

## Core Source

> Path: [`/src`](./src/)

Contains the core application logic, rule checks, generator, and console UI rendering routines.

| Project | Description |
|---------|--------------|
| `main.c` | Source code containing entry point, generator, strength checker, and UI animations |

### Features

| Feature | Description |
|---------|-------------|
| Password Generation | Randomly selects characters from lowercase, uppercase, digit, and special character pools |
| Strength Checking | Evaluates passwords against 5 security rules |
| Color-coded Output | Green = pass, Red = fail, Cyan = info, Yellow = prompts |
| Animated Printing | Characters print one at a time with `Sleep()` for a typewriter effect |
| Loading Animation | Dots animate while analyzing or generating |
| ASCII Banner | Stylized `PSGN` banner rendered in the console on startup |
| Retry Loop | Prompts user to try again after each action without restarting |

### How It Works

#### Password Generation

```
Seed RNG with current time (srand(time(NULL)))
         │
         ▼
Pick random length: 16–24 characters
         │
         ▼
For each position:
  - Pick a random character pool (lowercase / uppercase / digits / special)
  - Pick a random character from that pool
         │
         ▼
Print character-by-character with 50ms delay
         │
         ▼
Display password length and strength rating
```

The four character pools used:

```c
const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *digits    = "1234567890";
const char *special   = "!@#$^&*()_+-=";
```

#### Password Checking

The checker uses an array of function pointers (`standardPassword` typedef) to apply each rule independently:

```c
typedef int (*standardPassword)(const char *);

standardPassword rules[] = {
    isPasswordLong,
    isPasswordUp,
    isPasswordDig,
    isPasswordSpecial,
    isPasswordwithSpace
};
```

Each rule function receives the password string and returns `1` (pass) or `0` (fail). Results are printed with color-coded labels.

### Strength Rules

A password is considered strong if it satisfies all of the following:

| # | Rule | Function |
|---|------|----------|
| 1 | At least **16 characters** long | `isPasswordLong` |
| 2 | Contains at least one **uppercase letter** | `isPasswordUp` |
| 3 | Contains at least one **digit** | `isPasswordDig` |
| 4 | Contains at least one **special character** | `isPasswordSpecial` |
| 5 | Contains **no whitespace** | `isPasswordwithSpace` (inverse check) |

If any rule fails, the password is rated **Weak** and the specific failure is printed in red.

### Console UI Design

The UI is built entirely using Windows Console API and Unicode box-drawing characters.

#### Color Scheme

| Color | Usage |
|-------|-------|
| Cyan | Separators, section headers, info messages |
| Green | Passing checks, success messages |
| Red | Failing checks, error/invalid input |
| Yellow | User prompts, menu options |
| Magenta | ASCII banner art |

#### Techniques Used

- `SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)` — set text color
- `Sleep(ms)` — delays for animations and pacing
- Unicode box-drawing characters (`╔`, `║`, `╚`, `═`, `┌`, `─`, `┐`) for bordered UI elements
- `fflush(stdout)` — forces immediate character output for smooth animations

### Known Limitations

| Limitation | Notes |
|------------|-------|
| Windows-only | Uses `windows.h`, `Sleep()`, and `SetConsoleTextAttribute` — not portable to Linux/macOS |
| `rand()` seeding | Uses `srand(time(NULL))` — not cryptographically secure; sufficient for practice purposes |
| No clipboard support | Generated passwords must be manually copied |

### Future Improvements

- [ ] Cross-platform color support using ANSI escape codes
- [ ] Password entropy score displayed alongside strength rating
- [ ] Option to copy generated password to clipboard automatically
- [ ] Custom character set selection for generation
- [ ] Save generated passwords to an encrypted local file

---

## Build Configuration

> Path: [`.`](./)

Defines compilation scripts and workspace task automation.

| Project | Description |
|---------|--------------|
| `Makefile` | Automates compilation and cleaning routines for the application |

---

## Tools and Requirements

| Tool | Version | Purpose |
|------|---------|---------|
| [GCC (MinGW-w64)](https://www.mingw-w64.org/) | C99 or later | C compiler for Windows environment |
| [GNU Make](https://www.gnu.org/software/make/) | 3.81 or later | Build automation tool |
| Windows OS | Windows 7 or later | Required for Windows Console API (`windows.h`) |

---

## Getting Started

1. Set up a MinGW-w64 environment on Windows
2. Clone this repository and navigate to the directory
   ```bash
   git clone https://github.com/USERNAME/REPO.git
   cd PasGenCheck
   ```
3. Compile the application using the Makefile
   ```bash
   make
   ```
4. Run the generated executable
   ```bash
   ./pas_gen_check
   ```
5. Clean build files if necessary
   ```bash
   make clean
   ```

---

## License

This project is licensed under the [MIT License](LICENSE).

---

<div align="center">

Built with C and the Windows Console API.

Star this repository if it was useful.

</div>

