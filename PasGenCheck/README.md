# PasGenCheck — Password Generator & Checker

An interactive, color-coded console application written in C for generating cryptographically random passwords and checking the strength of existing ones. Features an animated terminal UI built with the Windows Console API.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [How It Works](#how-it-works)
  - [Password Generation](#password-generation)
  - [Password Checking](#password-checking)
- [Strength Rules](#strength-rules)
- [Console UI Design](#console-ui-design)
- [Project Structure](#project-structure)
- [Building & Running](#building--running)
- [Known Limitations](#known-limitations)
- [Future Improvements](#future-improvements)

---

## Overview

PasGenCheck is a single-file C program that provides two utilities in one interactive menu:

1. **Generate** — Produce a random, high-entropy password between 16 and 24 characters
2. **Check** — Analyze an existing password against a set of security rules and report its weaknesses

The program uses Windows Console API for colors and delays, giving it a polished, animated feel uncommon in console C programs.

---

## Features

| Feature | Description |
|---------|-------------|
| Password Generation | Randomly selects characters from lowercase, uppercase, digit, and special character pools |
| Strength Checking | Evaluates passwords against 5 security rules |
| Color-coded Output | Green = pass, Red = fail, Cyan = info, Yellow = prompts |
| Animated Printing | Characters print one at a time with `Sleep()` for a typewriter effect |
| Loading Animation | Dots animate while "analyzing" or "generating" |
| ASCII Banner | Stylized `PSGN` banner rendered in the console on startup |
| Retry Loop | Prompts user to try again after each action without restarting |

---

## How It Works

### Password Generation

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

### Password Checking

The checker uses an array of **function pointers** (`standardPassword` typedef) to apply each rule independently:

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

---

## Strength Rules

A password is considered **strong** if it satisfies **all** of the following:

| # | Rule | Function |
|---|------|----------|
| 1 | At least **16 characters** long | `isPasswordLong` |
| 2 | Contains at least one **uppercase letter** | `isPasswordUp` |
| 3 | Contains at least one **digit** | `isPasswordDig` |
| 4 | Contains at least one **special character** | `isPasswordSpecial` |
| 5 | Contains **no whitespace** | `isPasswordwithSpace` (inverse check) |

If any rule fails, the password is rated **Weak** and the specific failure is printed in red.

---

## Console UI Design

The UI is built entirely using Windows Console API and Unicode box-drawing characters.

### Color Scheme

| Color | Usage |
|-------|-------|
| Cyan | Separators, section headers, info messages |
| Green | Passing checks, success messages |
| Red | Failing checks, error/invalid input |
| Yellow | User prompts, menu options |
| Magenta | ASCII banner art |

### Techniques Used

- `SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)` — set text color
- `Sleep(ms)` — delays for animations and pacing
- Unicode box-drawing characters (`╔`, `║`, `╚`, `═`, `┌`, `─`, `┐`) for bordered UI elements
- `fflush(stdout)` — forces immediate character output for smooth animations

---

## Project Structure

```
PasGenCheck/
├── Makefile
└── src/
    └── main.c
```

All logic is contained in `src/main.c`, organized into focused functions:

| Function | Responsibility |
|----------|---------------|
| `greet()` | Renders the startup banner and menu |
| `generatePassword()` | Handles password generation flow |
| `checkPassword()` | Handles password checking flow |
| `exitProgram()` | Confirmation prompt before exit |
| `repeatProgram()` | Y/N loop to retry the current action |
| `isPasswordLong()` | Rule: minimum length |
| `isPasswordUp()` | Rule: uppercase presence |
| `isPasswordDig()` | Rule: digit presence |
| `isPasswordSpecial()` | Rule: special character presence |
| `isPasswordwithSpace()` | Rule: no whitespace |
| `setColor()` | Wrapper for console color change |
| `printWithDelay()` | Typewriter-effect printer |
| `loadingAnimation()` | Animated dots loader |
| `printSeparator()` | Prints a `═` separator line |

---

## Building & Running

### Prerequisites

- GCC (MinGW recommended on Windows)
- GNU Make
- Windows OS (required for `windows.h` APIs)

### Compile

From the `PasGenCheck/` directory:

```bash
make
```

This produces `pas_gen_check.exe`.

### Run

```bash
./pas_gen_check
```

### Clean

```bash
make clean
```

---

## Known Limitations

| Limitation | Notes |
|------------|-------|
| Windows-only | Uses `windows.h`, `Sleep()`, and `SetConsoleTextAttribute` — not portable to Linux/macOS |
| `rand()` seeding | Uses `srand(time(NULL))` — not cryptographically secure; sufficient for practice purposes |
| No clipboard support | Generated passwords must be manually copied |

---

## Future Improvements

- [ ] Cross-platform color support using ANSI escape codes
- [ ] Password entropy score displayed alongside strength rating
- [ ] Option to copy generated password to clipboard automatically
- [ ] Custom character set selection for generation
- [ ] Save generated passwords to an encrypted local file
