# README Format Specification

This document defines a reusable README structure, extracted from an existing project README. It is intended to be read and applied by an AI agent when generating new README files. No emojis are used; tone is formal and technical.

---

## 1. Overall Structure

A README built with this format follows this sequence:

1. Centered header block (title, tagline, badges, summary line)
2. Project category / table of contents table
3. One section per category, each containing a description and a details table
4. Tools and requirements table
5. Concepts or skills summary (optional progress-bar style block)
6. Repository structure tree
7. Getting started instructions
8. License section
9. Centered footer block

---

## 2. Header Block

Wrapped in an HTML `<div align="center">...</div>` block so it renders centered on GitHub. Contains, in order:

- A level-1 heading with the project name (no emoji prefix)
- A one-line bolded tagline
- A second descriptive line
- A row of badges (see Section 3)
- A horizontal rule (`---`)
- A blockquote summary line describing scope and compatibility

Template:

```html
<div align="center">

# Project Name

**Short bolded tagline describing the project**
A second line providing additional context.

[badges go here — see Section 3]

</div>

---

> Contextual summary line describing what the repository contains and any compatibility notes.

```

---

## 3. Badges

Badges are generated using the [shields.io](https://shields.io) service and embedded as Markdown image links wrapped in a hyperlink. Syntax pattern:

```markdown
[![Label](https://img.shields.io/badge/LEFT_TEXT-RIGHT_TEXT-COLOR?style=for-the-badge&logo=LOGO_NAME&logoColor=white)](TARGET_URL)
```

Rules for constructing a badge:

- `LEFT_TEXT` and `RIGHT_TEXT` use `%20` for spaces and `-` as the internal separator; a literal hyphen in the label must be escaped as `--`.
- `COLOR` is a hex code (no `#`) or a named color.
- `style=for-the-badge` produces the large rectangular badge style used throughout this format; omit for a smaller flat badge.
- `logo` accepts any [simple-icons](https://simpleicons.org) slug (e.g. `cisco`, `github`, `python`).
- The badge should link to a relevant external resource (official docs, certification page, license file).
- A count or metric badge (e.g. number of files) can be static, without a logo or link:

```markdown
![Label](https://img.shields.io/badge/LABEL-VALUE-COLOR?style=for-the-badge)
```

Place three to five badges in a single row, separated by line breaks or spaces.

---

## 4. Table of Contents / Category Table

Immediately after the header, provide a summary table listing every major section, linked to its anchor:

```markdown
| # | Category | Topics Covered | Files |
|---|----------|-----------------|-------|
| 1 | [Category Name](#category-anchor) | Short comma-separated topic list | Count |
```

Anchor links use GitHub's auto-generated heading slugs (lowercase, spaces replaced with hyphens).

---

## 5. Section Format

Each category from the table of contents becomes its own section, in the same order. Structure per section:

```markdown
## Category Name

> Path: [`/Folder Name`](./Folder%20Name/)

One or two sentences describing the purpose and skills covered by this category.

| Project | Description |
|---------|--------------|
| `filename.ext` | One-line description of what this file demonstrates |

[Optional] Reference link: [Supplementary Notes](./Folder%20Name/notes.md)
```

Notes:

- File paths with spaces use `%20` in the link target.
- The description table is the core content unit — one row per file/artifact.
- Keep descriptions factual and specific (what is configured, what protocol, what scenario), not promotional.

---

## 6. Tools and Requirements Table

A standard two-to-three column table listing required software and its purpose:

```markdown
## Tools and Requirements

| Tool | Version | Purpose |
|------|---------|---------|
| [Tool Name](URL) | Version constraint | What it is used for |

> Note: any setup caveat or compatibility note.
```

---

## 7. Concepts / Skills Summary (Optional)

A monospace code block used as a lightweight visual proficiency or coverage indicator, using block characters to simulate a progress bar:

```markdown
## Concepts Practiced

```
Concept Name A     ████████████████████  Full description of what was covered
Concept Name B     ███████████████░░░░░  Partial description
```
```

Each bar is 20 characters total, combining `█` (filled) and `░` (unfilled) to represent relative depth or completeness. This section is optional and should only be included when a coverage-style summary adds value.

---

## 8. Repository Structure

A fenced code block containing a plain-text directory tree, mirroring the actual folder layout:

```markdown
## Repository Structure

​```
project-name/
├── Folder One/
│   ├── file-one.ext
│   ├── file-two.ext
│   └── README.md
│
├── Folder Two/
│   ├── file-three.ext
│   └── README.md
│
└── README.md  ← current file
​```
```

Use standard box-drawing characters (`├──`, `└──`, `│`) with consistent indentation. Annotate the current file if relevant.

---

## 9. Getting Started

A numbered list of setup steps, using fenced code blocks for commands:

```markdown
## Getting Started

1. Install [Required Tool](URL)
2. Clone this repository
   ​```bash
   git clone https://github.com/USERNAME/REPO.git
   cd REPO
   ​```
3. Additional setup or usage step
4. Verification step
```

---

## 10. License Section

```markdown
## License

This project is licensed under the [MIT License](LICENSE).
```

Adjust license type as applicable; keep this section brief.

---

## 11. Footer Block

Mirrors the header: a centered `<div align="center">...</div>` block containing a short closing line and an optional call to action (e.g. requesting the repository be starred).

```html
<div align="center">

Built with [technology/tool names].

Star this repository if it was useful.

</div>
```

---

## 12. Tone and Style Rules for This Variant

When applying this format without emojis and with a formal register:

- Remove all emoji characters from headings, table cells, and bullet points.
- Replace emoji-led section markers with plain heading text (e.g. `## Basic Switching` instead of `## 🔀 Basic Switching`).
- Avoid exclamatory or promotional phrasing ("helped your studies!", "Made with ☕"); prefer neutral, descriptive statements.
- Keep sentence structure direct and technical; favor precise terminology over casual language.
- Badges, tables, and structural elements (blockquotes, code fences, centered divs) remain unchanged — only emoji and tone are affected, not layout mechanics.
