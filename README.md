# From C-Ro to Hero

> A personal collection of C programming projects built to practice systems programming, explore standard libraries, and go from zero to hero in C — one project at a time.

---

## Table of Contents

- [About](#about)
- [Repository Structure](#repository-structure)
- [Projects](#projects)
  - [ASCII Art in C](#ascii-art-in-c)
  - [PasGenCheck — Password Generator & Checker](#pasgencheck--password-generator--checker)
- [Prerequisites](#prerequisites)
- [Building the Projects](#building-the-projects)
  - [Build All Projects](#build-all-projects)
  - [Build Individually](#build-individually)
- [Roadmap](#roadmap)

---

## About

This repository is a growing collection of small-to-medium C programs built from scratch. Each project focuses on a different concept or library, with the goal of becoming proficient in C through deliberate, hands-on practice.

The projects here intentionally avoid "easy" alternatives (e.g., using Python for image processing) in order to build a deeper understanding of how things work at a lower level.

---

## Repository Structure

```
from-c-ero-to-hero/
├── .gitignore
├── Makefile                    # Root Makefile — builds all projects
├── README.md
│
├── ASCII Art in C/             # Image-to-ASCII art renderer
│   ├── Makefile
│   ├── asset/
│   │   └── documentation.txt
│   ├── include/
│   │   ├── stb_image.h
│   │   └── stb_image_resize2.h
│   └── src/
│       ├── main.c
│       └── demo_image.png
│
└── PasGenCheck/                # Password generator & strength checker
    ├── Makefile
    └── src/
        └── main.c
```

---

## Projects

### ASCII Art in C

**Directory:** [`ASCII Art in C/`](./ASCII%20Art%20in%20C/)

A terminal program that converts any image file into ASCII art, rendered character-by-character directly in the console.

#### How It Works

| Step | Description |
|------|-------------|
| 1. Load image | Uses `stb_image.h` to load and decode the image, converting it to grayscale on the fly |
| 2. Resize | Downscales the image using `stb_image_resize2.h` to fit inside the terminal |
| 3. Map intensity | Each pixel's brightness (0–255) is mapped to a character in the set `.-~+=:;oaAOD0%&$B8MW#@` |
| 4. Render | Prints each character with a trailing space to compensate for the terminal's aspect ratio |

#### Libraries Used

- [`stb_image.h`](https://github.com/nothings/stb/blob/master/stb_image.h) — Single-header image loading library
- [`stb_image_resize2.h`](https://github.com/nothings/stb/blob/master/stb_image_resize2.h) — Single-header image resizing library

#### Running

```bash
cd "ASCII Art in C"
make
./ascii_art
# Enter image filename when prompted, e.g.: demo_image.png
```

> **Note:** The image file must be located in the same directory as the executable, or you must provide an absolute path.

---

### PasGenCheck — Password Generator & Checker

**Directory:** [`PasGenCheck/`](./PasGenCheck/)

A stylized, interactive console application with two modes: **generate** a cryptographically random password, or **check** the strength of an existing one. Features a fully animated, color-coded terminal UI using Windows Console API.

#### Features

| Feature | Details |
|---------|---------|
| Password Generation | Generates a random 16–24 character password from lowercase, uppercase, digits, and special characters |
| Strength Checking | Validates against 5 rules (length, uppercase, digits, special chars, no spaces) |
| Color-coded Output | Green for pass, red for fail, cyan for info — using `SetConsoleTextAttribute` |
| Animated UI | Character-by-character print with `Sleep()` delays for a polished look |
| ASCII Banner | Full PSGN banner rendered in the console on startup |

#### Password Strength Rules

A password is considered **strong** if it meets all of the following:

- At least **16 characters** long
- Contains at least one **uppercase letter**
- Contains at least one **digit**
- Contains at least one **special character** (`!@#$^&*()_+-=`)
- Contains **no spaces**

#### Running

```bash
cd PasGenCheck
make
./pas_gen_check
```

> **Note:** This project uses Windows-specific APIs (`windows.h`, `SetConsoleTextAttribute`, `Sleep`). It is intended to be compiled and run on Windows.

---

## Prerequisites

Ensure you have the following installed:

- **GCC** (MinGW on Windows recommended) — `gcc --version`
- **GNU Make** — `make --version`
- A terminal that supports **UTF-8** for the best rendering experience

---

## Building the Projects

### Build All Projects

From the root of the repository:

```bash
make
```

To clean all compiled binaries:

```bash
make clean
```

### Build Individually

#### ASCII Art in C

```bash
cd "ASCII Art in C"
make        # compile
make clean  # remove binary
```

#### PasGenCheck

```bash
cd PasGenCheck
make        # compile
make clean  # remove binary
```

---

## Roadmap

### ASCII Art in C
- [ ] Accept image path as a command-line argument
- [ ] Auto-detect terminal size and scale output accordingly
- [ ] Support color ASCII art using ANSI escape codes
- [ ] Cross-platform terminal support (Linux/macOS)

### PasGenCheck
- [ ] Cross-platform color support (ANSI escape codes for Linux/macOS)
- [ ] Add password entropy calculation and display
- [ ] Option to copy generated password to clipboard
- [ ] Support for custom character sets in generation

---

> Built by learning, broken by curiosity, fixed by persistence.
