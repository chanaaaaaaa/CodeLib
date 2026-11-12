# AGENTS.md

## Cursor Cloud specific instructions

This is a personal code library / competitive programming repository ("CodeLib"). It contains independent code artifacts — **not** a service-oriented application. There are no servers, APIs, databases, or build pipelines.

### Repository structure

| Directory | Contents |
|---|---|
| `code/day-*/` | Competitive programming solutions in C++ (UVa, CSES, AtCoder, APCS) |
| `AlgorithmLib/` | Classic algorithm implementations in C++ (Dijkstra, Kruskal, LIS, LCS, etc.) |
| `screeps/` | JavaScript bot scripts for the Screeps game |
| `AutoUpdateStudentRssForCPS/` | Python automation script (Selenium + Pandas) |
| `2025-*-* 海大/` | Programming contest solutions |

### Development tools

- **C++**: Compile individual `.cpp` files with `g++ -O2 -o output file.cpp`. No build system or Makefile exists.
- **Python**: Dependencies in `AutoUpdateStudentRssForCPS/release/requirements_club_automation.txt`. Install with `pip3 install -r AutoUpdateStudentRssForCPS/release/requirements_club_automation.txt`.
- **JavaScript (Screeps)**: No package manager needed. Scripts are deployed to the Screeps game server. Syntax-check with `node --check <file>.js`.

### Caveats

- There are **no automated tests, linters, or CI/CD pipelines** in this repo.
- Many `.cpp` files use `#pragma GCC optimize(...)` and `#pragma GCC target(...)` directives — these are competitive programming optimizations and may produce warnings but are harmless.
- File and directory names may contain spaces and non-ASCII characters (Chinese). Always quote paths in shell commands.
- The Screeps scripts depend on the Screeps game API (`Game`, `Memory`, etc.) — they cannot be `require()`d in a standard Node.js environment, only syntax-checked.
