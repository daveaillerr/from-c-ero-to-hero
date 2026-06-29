# ASCII Art in C

A terminal program that converts any image file into ASCII art, rendered directly in the console using C and single-header STB libraries.

> Built as a deliberate challenge — refusing to use Python where it would have been trivially easy — in order to understand image processing at a lower level.

---

## Table of Contents

- [Overview](#overview)
- [Goals](#goals)
- [How It Works](#how-it-works)
- [Algorithm Breakdown](#algorithm-breakdown)
- [Libraries](#libraries)
- [Project Structure](#project-structure)
- [Building & Running](#building--running)
- [Known Issues & Fixes](#known-issues--fixes)
- [Future Improvements](#future-improvements)

---

## Overview

This project reads an image file from disk, downscales it to fit the terminal, converts it to grayscale, and maps each pixel's brightness to an ASCII character. The result is an ASCII rendering of the original image printed directly to standard output.

---

## Goals

- Learn how to use external single-header C libraries (`stb_image`, `stb_image_resize2`)
- Understand image representation — channels, pixels, and grayscale conversion
- Practice writing clean, readable C code
- Produce a visible, working output: an ASCII rendering of any input image

---

## How It Works

At a high level, the program follows this pipeline:

```
Input Image File
      │
      ▼
 Load & Decode (stb_image)
 → grayscale, width, height
      │
      ▼
 Downscale (stb_image_resize2)
 → fits terminal dimensions
      │
      ▼
 Intensity Mapping
 → pixel brightness (0–255) → ASCII character
      │
      ▼
 Print to Terminal
```

---

## Algorithm Breakdown

### 1. Define the ASCII Character Set

A string of characters is arranged from **darkest** (least dense) to **brightest** (most dense):

```c
char value[] = ".-~+=:;oaAOD0%&$B8MW#@";
```

Characters on the left represent dark/empty regions; characters on the right represent bright/dense regions.

### 2. Load & Grayscale the Image

Using `stb_image.h`, the image is loaded and immediately converted to a single-channel grayscale representation by passing `1` as the desired channel count:

```c
unsigned char *input_image = stbi_load(image_name, &width, &height, &channel, 1);
```

Each pixel in the resulting buffer is a single `unsigned char` (0 = black, 255 = white).

### 3. Downscale to Terminal Size

The image is resized so it fits within a reasonable terminal window. The divisors control the output dimensions:

```c
int output_w = width / 35;
int output_h = height / 45;
stbir_resize_uint8_srgb(input_image, width, height, 0,
                         output_image, output_w, output_h, 0,
                         STBIR_1CHANNEL);
```

> The width and height divisors are different to compensate for the terminal character aspect ratio (characters are taller than they are wide).

### 4. Compute & Map Pixel Intensity

For each pixel in the resized image, its grayscale value (0–255) is mapped to an index in the ASCII character array:

```c
int ascii_index = (b * 20) / 255;
printf("%c ", value[ascii_index]);
```

A space is printed after each character to maintain the correct aspect ratio.

### 5. Print the Image

The nested loop iterates row by row, printing each character and inserting a newline at the end of each row.

---

## Libraries

| Library | Purpose | Source |
|---------|---------|--------|
| `stb_image.h` | Load and decode image files (PNG, JPG, BMP, etc.) into raw pixel data | [nothings/stb](https://github.com/nothings/stb) |
| `stb_image_resize2.h` | Resize pixel buffers using high-quality resampling | [nothings/stb](https://github.com/nothings/stb) |

Both are **single-header libraries** — no external dependencies or linking required. Simply `#include` them with the appropriate `#define` before the include.

---

## Project Structure

```
ASCII Art in C/
├── Makefile
├── asset/
│   └── documentation.md      # This file
├── include/
│   ├── stb_image.h
│   └── stb_image_resize2.h
└── src/
    ├── main.c
    └── demo_image.png        # Sample image for testing
```

---

## Building & Running

### Prerequisites

- GCC (or any C99-compatible compiler)
- GNU Make

### Compile

From the `ASCII Art in C/` directory:

```bash
make
```

This produces an executable named `ascii_art` (or `ascii_art.exe` on Windows).

### Run

```bash
./ascii_art
```

When prompted, enter the filename of an image:

```
Enter your image name and extension: demo_image.png
```

> The image must be in the **same directory as the executable**, or provide a full path.

### Clean

```bash
make clean
```

---

## Known Issues & Fixes

| Issue | Status | Notes |
|-------|--------|-------|
| File location problem | In progress | Image must currently be in the same directory as the executable |
| Terminal size problem | In progress | Output dimensions are hardcoded divisors, not dynamically read from terminal size |
| Code cleanliness | In progress | `goto` used for loop control; to be refactored |

---

## Future Improvements

- [ ] Accept image path as a command-line argument (`./ascii_art path/to/image.png`)
- [ ] Auto-detect terminal width/height using `GetConsoleScreenBufferInfo` (Windows) or `ioctl` (Unix)
- [ ] Support color ASCII art using ANSI escape codes
- [ ] Cross-platform support (Linux/macOS)
- [ ] Export ASCII output to a `.txt` file
