# Maximum Non Negative Product in a Matrix

## Problem Description

You are given a matrix of size m x n. You start from the top-left corner (0, 0) and can only move either right or down.

Each path from the top-left to the bottom-right corner has a product of all values along the path.

Your task is to find the maximum non-negative product among all possible paths. If all possible products are negative, return -1.

Return the result modulo 10^9 + 7.

---

## Approach

This problem uses Dynamic Programming.

At each cell, we keep track of two values:
- Maximum product up to this cell
- Minimum product up to this cell

We need both because multiplying by a negative number can turn a minimum product into a maximum product and vice versa.

---

## Steps

1. Create two 2D arrays:
   - max_dp for maximum products
   - min_dp for minimum products

2. Initialize the first cell with the value of grid[0][0].

3. Fill the first row and first column since they have only one path.

4. For each cell (i, j), calculate:
   - All possible products from top and left
   - Update max_dp[i][j] with maximum value
   - Update min_dp[i][j] with minimum value

5. Final answer is max_dp[m-1][n-1]:
   - If it is negative, return -1
   - Otherwise return value modulo 10^9 + 7

---

## Complexity

Time Complexity: O(m * n)  
Space Complexity: O(m * n)

---

## Example

Input:
grid = [[1,-2,1],[1,-2,1],[3,-4,1]]

Output:
8

Explanation:
The path gives product 1 * 1 * -2 * -4 * 1 = 8
