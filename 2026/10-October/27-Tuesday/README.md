
# LeetCode 3963 — Create Grid With Exactly One Path

## Problem Statement
Create an `m × n` grid containing free cells (`.`) and blocked cells (`#`) such that there is exactly one valid path through the grid, according to the problem's movement rules.

## Approach
The solution constructs a path along the top row and the rightmost column.

1. Initialize all cells with `#`, representing blocked cells.
2. Fill the first row with `.` to create a horizontal path.
3. Fill the last column with `.` to create a vertical path.
4. Return the resulting grid.

This creates an L-shaped path from the top-left corner to the bottom-right corner.

## C Solution

```c
#include <stdlib.h>

char** createGrid(int m, int n, int* returnSize) {
    char** grid = malloc(m * sizeof(char*));
    *returnSize = m;

    for (int i = 0; i < m; i++) {
        grid[i] = malloc((n + 1) * sizeof(char));

        for (int j = 0; j < n; j++) {
            grid[i][j] = '#';
        }

        grid[i][n] = '\0';
    }

    for (int j = 0; j < n; j++) {
        grid[0][j] = '.';
    }

    for (int i = 0; i < m; i++) {
        grid[i][n - 1] = '.';
    }

    return grid;
}
```

## Complexity Analysis

- **Time Complexity:** `O(m × n)` — Initializing the grid requires visiting every cell.
- **Space Complexity:** `O(m × n)` — The grid stores `m × n` cells.

## Key Concepts

- Two-dimensional arrays
- Grid traversal
- Path construction
- Memory allocation in C

