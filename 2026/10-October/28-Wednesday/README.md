LeetCode 3882 --- Minimum XOR Path in a Grid

Problem

Given a grid of integers, find the minimum XOR value among all paths
from the top-left cell to the bottom-right cell. You may move only
right or down.

The XOR value of a path is the bitwise XOR of the values of all cells
visited along that path, including the starting and ending cells.

Python Solution

class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])

        dp = [[set() for _ in range(n)] for _ in range(m)]
        dp[0][0].add(grid[0][0])

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue

                if i > 0:
                    for x in dp[i - 1][j]:
                        dp[i][j].add(x ^ grid[i][j])

                if j > 0:
                    for x in dp[i][j - 1]:
                        dp[i][j].add(x ^ grid[i][j])

        return min(dp[m - 1][n - 1])

Approach: Dynamic Programming with Sets

dp[i][j] stores every distinct XOR value that can be obtained by a
valid path from the top-left cell to cell (i, j).

The starting cell initializes the first state:
dp[0][0] = {grid[0][0]}.

For each other cell, extend every XOR value from the cell above and
the cell to the left by XOR-ing it with the current cell's value.

The answer is the smallest XOR value stored at the bottom-right
cell.

A set is used because multiple paths can produce the same XOR value, and
duplicates do not need to be stored.

Example

Input

grid = [[1, 2],
        [3, 4]]

Possible paths:

Right, then down: 1 ^ 2 ^ 4 = 7

Down, then right: 1 ^ 3 ^ 4 = 6

Output

6

Complexity Analysis

Let K be the maximum number of distinct XOR values stored in any DP
state.

Time Complexity: O(m × n × K) in the general case.

Space Complexity: O(m × n × K) in the general case.

Here, m is the number of rows and n is the number of columns. The
actual performance depends on how many distinct XOR values each cell can
hold.
