
# 1254. Number of Closed Islands

## Problem Statement
Given a 2D grid consisting of `0`s (land) and `1`s (water), return the number of **closed islands**.

An island is a group of connected `0`s, where cells are connected horizontally or vertically. A closed island is an island completely surrounded by `1`s and does not touch the grid boundary.

## Approach: Depth-First Search (DFS)

1. Traverse the grid, excluding the boundary cells.
2. Whenever an unvisited land cell (`0`) is found, perform DFS.
3. Mark each visited land cell as `1` to avoid revisiting it.
4. During DFS, check all four directions: up, down, left, and right.
5. If the DFS reaches outside the grid, the island is not closed.
6. If all connected land cells remain within the grid, increment the closed island count.

## Python Solution

```python
from typing import List

class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        def dfs(r, c):
            if r < 0 or r >= m or c < 0 or c >= n:
                return False

            if grid[r][c] == 1:
                return True

            grid[r][c] = 1

            up = dfs(r - 1, c)
            down = dfs(r + 1, c)
            left = dfs(r, c - 1)
            right = dfs(r, c + 1)

            return up and down and left and right

        count = 0

        for r in range(1, m - 1):
            for c in range(1, n - 1):
                if grid[r][c] == 0:
                    if dfs(r, c):
                        count += 1

        return count
```

## Complexity Analysis

- **Time Complexity:** `O(m × n)` — Each cell is visited at most once.
- **Space Complexity:** `O(m × n)` — The recursive DFS stack can grow up to the number of cells.

Here, `m` is the number of rows and `n` is the number of columns.

