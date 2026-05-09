# 1914. Cyclically Rotating a Grid

## Problem Statement
Given an `m x n` matrix `grid`, rotate each layer of the grid counter-clockwise by `k` positions and return the rotated grid.
 
A layer is formed by the outer boundary of the matrix and progressively inner boundaries.

---

## Approach

### Steps
1. Traverse every layer of the matrix.
2. Extract all elements of the current layer into a list.
3. Rotate the list by `k % size_of_layer`.
4. Place rotated elements back into the matrix.

---

## Python Solution

```python
class Solution:
    def rotateGrid(self, grid, k):
        m, n = len(grid), len(grid[0])
        layers = min(m, n) // 2

        for layer in range(layers):
            elements = []

            # top row
            for j in range(layer, n - layer):
                elements.append(grid[layer][j])

            # right column
            for i in range(layer + 1, m - layer - 1):
                elements.append(grid[i][n - layer - 1])

            # bottom row
            for j in range(n - layer - 1, layer - 1, -1):
                elements.append(grid[m - layer - 1][j])

            # left column
            for i in range(m - layer - 2, layer, -1):
                elements.append(grid[i][layer])

            # rotate
            k_mod = k % len(elements)
            rotated = elements[k_mod:] + elements[:k_mod]

            idx = 0

            # top row
            for j in range(layer, n - layer):
                grid[layer][j] = rotated[idx]
                idx += 1

            # right column
            for i in range(layer + 1, m - layer - 1):
                grid[i][n - layer - 1] = rotated[idx]
                idx += 1

            # bottom row
            for j in range(n - layer - 1, layer - 1, -1):
                grid[m - layer - 1][j] = rotated[idx]
                idx += 1

            # left column
            for i in range(m - layer - 2, layer, -1):
                grid[i][layer] = rotated[idx]
                idx += 1

        return grid

        Complexity Analysis
Time Complexity: O(m × n)
Space Complexity: O(m + n) for storing one layer
Example
Input
grid = [[40,10],[30,20]]
k = 1
Output
[[10,20],[40,30]]
