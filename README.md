# Task 4 – Tic-Tac-Toe (C++)

Two-player console game on a 3×3 `char` matrix.

## Features
- Board redrawn after every move (cells numbered 1–9)
- Rejects invalid input and already-taken cells
- Turn switching X ↔ O
- Win detection for rows, columns and both diagonals; draw detection
- Running scoreboard and replay option

## Concepts used
2D arrays, functions, loops, turn logic, input validation.

## Build & Run
```bash
g++ -std=c++17 -Wall -Wextra tictactoe.cpp -o tictactoe
./tictactoe
```

## Files
| File | Purpose |
|------|---------|
| `tictactoe.cpp` | Source code |
| `sample_output.txt` | Captured game output |
