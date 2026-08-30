<div align="center">

# C Programming Basics

**Fundamental C Programming Exercises & Module Implementations**
Comprehensive collection of C standard library practices, algorithms, data structures, and terminal applications.

[![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c)
[![Compiler](https://img.shields.io/badge/Compiler-GCC-00599C?style=for-the-badge&logo=gnu&logoColor=white)](https://gcc.gnu.org/)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](https://opensource.org/licenses/MIT)

</div>

---

> Core C language syntax, algorithm implementations, memory management patterns, pointer operations, and basic data structures organized by topic.

---

| # | Category | Topics Covered | Files |
|---|----------|-----------------|-------|
| 1 | [Applications](#applications) | Bank management system, calculator, mobile billing app | 3 |
| 2 | [Arrays](#arrays) | Array traversal, copy operations, duplicate element detection, average calculation | 3 |
| 3 | [Conditional Constructs](#conditional-constructs) | If-else logic, ATM transactions, bonus calculation, cashier system, day mapping | 4 |
| 4 | [File Handling](#file-handling) | File append operations, expense tracking, conditional file reading | 4 |
| 5 | [Functions](#functions) | Arithmetic functions, geometry calculations, ASCII table, binary conversion, parity check | 5 |
| 6 | [Linked Lists](#linked-lists) | Singly linked list creation, enrollment system, node manipulation, middle element search | 6 |
| 7 | [Loops](#loops) | 2D matrix iteration, pattern printing (pyramid, wizard), ghost loop logic | 5 |
| 8 | [Pointers](#pointers) | Pointer arithmetic, sum/average calculations, array indexing, function pointers | 7 |
| 9 | [Strings](#strings) | String comparison, concatenation, string copy, length calculation, string reversal, truncation | 6 |
| 10 | [Structures](#structures) | Car info, employee database, grocery store, movie booking system, pet records | 6 |

---

## Applications

> Path: [`/Applications`](./Applications/)

Real-world console applications demonstrating modular C program control flow and state management.

| Project | Description |
|---------|--------------|
| `app_bankman.c` | Console bank account management program handling balance and transfers |
| `app_calcu.c` | Interactive command-line calculator performing basic arithmetic operations |
| `app_mobile.c` | Mobile service plan billing calculator application |

---

## Arrays

> Path: [`/Arrays`](./Arrays/)

Array initialization, element traversal, and array manipulation algorithms.

| Project | Description |
|---------|--------------|
| `array_averagge.c` | Computes average and sum of floating point array elements |
| `array_copyarray.c` | Copies elements from source array into target destination array |
| `array_duplicates.c` | Identifies and prints duplicate values present within an integer array |

---

## Conditional Constructs

> Path: [`/Conditional Constructs`](./Conditional%20Constructs/)

Decision-making using `if`, `else if`, `else`, and conditional evaluation logic.

| Project | Description |
|---------|--------------|
| `if_atm.c` | Simulates ATM PIN verification and cash withdrawal logic |
| `if_bonus.c` | Calculates employee performance bonus tiers using nested conditionals |
| `if_cashier.c` | Calculates checkout total and discount rates for retail POS cashier |
| `if_days.c` | Maps day numbers to corresponding weekday names |

---

## File Handling

> Path: [`/File Handling`](./File%20Handling/)

File I/O operations using standard C library functions (`fopen`, `fprintf`, `fscanf`, `fclose`).

| Project | Description |
|---------|--------------|
| `filehandling_append.c` | Demonstrates appending new record lines to an existing text file |
| `filehandling_expensetracker.c` | Implements an expense tracking log written directly to disk |
| `filehandling_read.c` | Reads and displays text file contents line-by-line |
| `filehandling_readcondition.c` | Filters and displays file records based on matching query conditions |

---

## Functions

> Path: [`/Functions`](./Functions/)

Function definition, parameter passing, return values, and mathematical logic.

| Project | Description |
|---------|--------------|
| `function_addmult.c` | Performs addition and multiplication through user-defined functions |
| `function_area.c` | Computes geometric area for circles, rectangles, and triangles |
| `function_ascii.c` | Converts characters to ASCII numerical codes |
| `function_binary.c` | Converts decimal integer input into binary format |
| `function_even.c` | Determines parity (even vs odd) of input numbers |

---

## Linked Lists

> Path: [`/Linked Lists`](./Linked%20Lists/)

Dynamic memory allocation and pointer-based linked list data structure operations.

| Project | Description |
|---------|--------------|
| `linkedlist_createlist.c` | Creates and populates a dynamic singly linked list |
| `linkedlist_enrollment.c` | Manages student enrollment records using a linked list |
| `linkedlist_example.c` | Demonstrates basic node insertion and traversal routines |
| `linkedlist_integers.c` | Stores and searches integer series within a linked list |
| `linkedlist_middle.c` | Finds the middle node of a singly linked list using fast and slow pointers |
| `linkedlist_student.c` | Implements student database records stored in dynamic linked nodes |

---

## Loops

> Path: [`/Loops`](./Loops/)

Repetitive execution patterns using `for`, `while`, and 2D nested loops.

| Project | Description |
|---------|--------------|
| `loop_for2Darray.c` | Iterates and prints elements of a 2D grid matrix |
| `loop_for2Darray2.c` | Computes row-wise and column-wise totals in a 2D array |
| `loop_forghost.c` | Demonstrates conditional loop iteration with escape conditions |
| `loop_forpyramid.c` | Prints formatted character pyramid patterns using nested loops |
| `loop_forwizard.c` | Interactive game loop pattern exercising variable state updates |

---

## Pointers

> Path: [`/Pointers`](./Pointers/)

Direct memory address manipulation, pointer arithmetic, and reference semantics.

| Project | Description |
|---------|--------------|
| `pointer_arithmetic.c` | Demonstrates incrementing and decrementing raw pointer addresses |
| `pointer_arithmeticsum.c` | Computes array sum using pointer offset arithmetic |
| `pointer_average.c` | Calculates element averages passing array pointers to functions |
| `pointer_demo.c` | Basic pointer variable declaration and dereferencing demonstration |
| `pointer_elements.c` | Accesses multi-element arrays using pointer subscripting |
| `pointer_function.c` | Demonstrates function pointers as callback parameters |
| `pointer_inarray.c` | Searches array elements via pointer traversal |

---

## Strings

> Path: [`/Strings`](./Strings/)

Null-terminated character array manipulation and standard string function algorithms.

| Project | Description |
|---------|--------------|
| `string_compare.c` | Compares two character strings character-by-character |
| `string_concat.c` | Appends one string to the end of another string buffer |
| `string_copy.c` | Copies source string contents into destination string buffer |
| `string_length.c` | Calculates string character count without including null terminator |
| `string_reverse.c` | Reverses character sequence in place within a string |
| `string_trunc.c` | Truncates strings to specified maximum lengths |

---

## Structures

> Path: [`/Structures`](./Structures/)

User-defined composite data types using C `struct`.

| Project | Description |
|---------|--------------|
| `structures_carinfo.c` | Defines and manages vehicle record structures |
| `structures_employeemanagement.c` | Employee directory tracking IDs, names, and salaries |
| `structures_grocery.c` | Inventory stock management for grocery items using structs |
| `structures_moviebooking.c` | Ticket booking system utilizing structured seat records |
| `structures_petrecord.c` | Stores pet medical and adoption history data structures |
| `structures_studentdatabase.c` | Student grade point database array of structs |

---

## Tools and Requirements

| Tool | Version | Purpose |
|------|---------|---------|
| [GCC](https://gcc.gnu.org/) | C99 or later | C compiler for source compilation |

---

## Getting Started

1. Navigate to the `Basics` directory or any specific category folder:
   ```bash
   cd Basics/Pointers
   ```
2. Compile any source file using GCC:
   ```bash
   gcc src/pointer_demo.c -o pointer_demo
   ```
3. Run the compiled executable:
   ```bash
   ./pointer_demo
   ```

---

## License

This project is licensed under the [MIT License](LICENSE).

---

<div align="center">

Built with C.

Star this repository if it was useful.

</div>
