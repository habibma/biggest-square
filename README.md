# BSQ - Biggest Square Finder

A C program that finds the largest square of empty cells in a 2D map and marks it with a specified character.

## Overview

BSQ (Biggest Square) reads a map containing obstacles and empty cells, then uses dynamic programming to locate the largest square that can be formed using only empty cells. All empty cells within that square are marked with a "full" character to visualize the solution.

When multiple solutions of the same size exist, the program prioritizes:
1. Squares closest to the top of the map
2. Squares closest to the left

## Building

### Requirements
- GCC compiler
- Standard C library (C99 standard)
- `make` utility

### Compile

```bash
make
```

This creates the `bsq` executable.

### Clean Up

```bash
make clean       # Remove object files
make fclean      # Remove object files and executable
make re          # Clean and rebuild
```

## Usage

### Command Line

```bash
./bsq <map_file> [<map_file2> ...]
```

Process one or more map files:

```bash
./bsq example
./bsq map1.txt map2.txt map3.txt
```

### Standard Input

If no files are provided, the program reads from standard input:

```bash
./bsq < input.txt
```

Or type the map directly:

```bash
./bsq
9.ox
...........................
....O......................
............O..............
.................
....O......................
...............O...........
...........................
......O..............O.....
..O.......O................
```

## Input Format

### First Line: Map Metadata

The first line contains metadata in the format: `<lines><empty_char><obstacle_char><full_char>`

- **`<lines>`**: Number of rows in the map (decimal digits)
- **`<empty_char>`**: Character representing empty cells (any printable character)
- **`<obstacle_char>`**: Character representing obstacles (any printable character)
- **`<full_char>`**: Character to mark the solution square (any printable character)

**Important:** All three characters must be different.

### Example Metadata Line

```
9.ox
```

- Map has 9 rows
- Empty cells: `.`
- Obstacles: `O`
- Solution marker: `x`

### Map Grid

Following lines contain the actual map:
- Each row must have exactly the same number of columns as the first row has characters (excluding newline)
- Each row must end with a newline
- All characters must be one of: empty, obstacle, or full character (after processing)

### Complete Example

```
9.ox
...........................
....O......................
............O..............
.................
....O......................
...............O...........
...........................
......O..............O.....
..O.......O................
```

## Output

The program outputs the map with the largest square of empty cells replaced by the full character. Each input file's output is followed by a blank line.

### Example Output

```
.....xxxxxxx...............
....Oxxxxxxx...............
.....xxxxxxxO..............
.....xxxxxxx...............
....Oxxxxxxx...............
.....xxxxxxx...O...........
.....xxxxxxx...............
......O..............O.....
..O.......O................
```

## Error Handling

If an input map is invalid, the program prints `map error` to standard error and continues with the next file.

### Invalid Map Conditions

- Any line has a different length than the others
- A map contains fewer than 1 row or 0 columns
- A map contains characters other than empty, obstacle, or full
- The metadata line has duplicate characters or is malformed
- A metadata line is missing or too short

## Algorithm

The solution uses **dynamic programming**:

1. Create a 2D DP array where `dp[i][j]` = size of the largest square with `(i,j)` as the bottom-right corner
2. For each cell:
   - If it's empty, compute: `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1`
   - If it's an obstacle, set: `dp[i][j] = 0`
3. Track the position and size of the maximum square
4. Mark all cells of that square with the full character

**Time Complexity:** O(rows × cols)  
**Space Complexity:** O(rows × cols)

## Files

- `src/main.c` - Entry point and file handling
- `src/bsq.c` - Main orchestration function
- `src/parse.c` - Map parsing and grid allocation
- `src/validate.c` - Map validation
- `src/solve.c` - Dynamic programming solver
- `src/print.c` - Output formatting
- `src/init.c` - Initialization
- `src/clean.c` - Memory cleanup
- `utils.c` - Utility functions (line reading, memory allocation)
- `include/map.h` - Header with data structures and prototypes
- `Makefile` - Build configuration

## Memory Management

The program properly allocates and frees all dynamically allocated memory, including:
- Grid rows and columns
- Temporary line buffers
- Dynamic programming arrays

Memory is cleaned up on both successful completion and error paths.

## Testing

Run the included example:

```bash
./bsq example
```

With Valgrind (requires Valgrind installation):

```bash
valgrind ./bsq example
```

Check for memory leaks and errors in program execution.

## Author

Created as a programming exercise to practice dynamic programming and C memory management.

You can read the step-by-step article about how I built this program in C on Medium: [How I Built BSQ in C Step by Step](https://medium.com/@habib.motavassel/how-i-built-bsq-in-c-step-by-step-3d81aa6fe842)
