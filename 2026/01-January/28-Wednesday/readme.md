# Minimum Cost Path with Teleportation

This project solves a grid pathfinding problem where you can move normally
or use limited teleportation to reduce the total cost.

## Problem Summary

- You are given a 2D grid of integers.
- You start from the top-left cell `(0, 0)`.
- The goal is to reach the bottom-right cell.
- You can move only right or down.
- Each move adds the cost of the destination cell.
- You can teleport at most `k` times:
  - You may teleport from any cell to another cell with value less than or equal to the current cell.
  - Teleporting costs `0`.

The objective is to find the minimum possible cost to reach the destination.

## Approach

- Dynamic Programming is used.
- `dp[t][i][j]` represents the minimum cost to reach cell `(i, j)` using `t` teleports.
- For each teleport count:
  - Teleport transitions are applied first, processed by cell values in descending order.
  - After that, normal right and down moves are applied.

This order ensures teleportation does not break the path constraints.

## Complexity

- Time complexity: `O(k × m × n)`
- Space complexity: `O(k × m × n)`

This solution works efficiently within the given limits.

## Result

- All edge cases are handled.
- All test cases pass successfully.
- The solution follows the editorial approach.

## Files

- `Solution.java` – main implementation
