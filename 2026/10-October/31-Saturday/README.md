LeetCode 3665 --- Twisted Mirror Path Count
Difficulty: Medium
Topics: Dynamic Programming, Matrix, Simulation
Problem: Twisted Mirror Path
Count
Problem Summary
Given an m x n binary grid:
- 0 represents an empty cell.
- 1 represents a mirror.
A robot starts at (0, 0) and must reach (m - 1, n - 1), moving only
right or down.

When the robot attempts to enter a mirror:
- Moving right into a mirror redirects it one cell down.
- Moving down into a mirror redirects it one cell right.
If a reflection reaches another mirror, that mirror immediately reflects
the robot again. Any route that leaves the grid is invalid.

Return the number of valid paths modulo 1,000,000,007.
Approach: 2D Dynamic Programming with Direction States
Use dp[i][j][d] to count the number of ways to arrive at cell
(i, j):
- d = 0: arriving while moving right (from the left).
- d = 1: arriving while moving down (from above).
Initialize dp[0][0][0] = 1. The starting cell is guaranteed to be
empty, so processing it sends the initial path count both right and
down.

For each cell:
1. Empty cell (0): Combine both incoming direction counts. The
   resulting paths can continue right and down.
2. Mirror (1): Do not combine the incoming counts. Paths arriving
   from the left are redirected down, while paths arriving from above
   are redirected right.
3. Ignore moves that would leave the grid.
4. Apply modulo after each update.
Because every transition moves only right or down, processing cells in
row-major order ensures that all incoming counts are ready when a cell
is processed.
Java Solution
class Solution {
    public int uniquePaths(int[][] grid) {
        final int MOD = 1_000_000_007;
        int m = grid.length;
        int n = grid[0].length;

        int[][][] dp = new int[m][n][2];
        dp[0][0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int fromLeft = dp[i][j][0];
                int fromAbove = dp[i][j][1];

                if (grid[i][j] == 0) {
                    int ways = (fromLeft + fromAbove) % MOD;

                    if (j + 1 < n) {
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + ways) % MOD;
                    }

                    if (i + 1 < m) {
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + ways) % MOD;
                    }
                } else {
                    // Entering from the left: reflect downward.
                    if (i + 1 < m) {
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + fromLeft) % MOD;
                    }

                    // Entering from above: reflect rightward.
                    if (j + 1 < n) {
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + fromAbove) % MOD;
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] +
                dp[m - 1][n - 1][1]) % MOD;
    }
}
C++ Solution
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1'000'000'007;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(2, 0))
        );

        dp[0][0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int fromLeft = dp[i][j][0];
                int fromAbove = dp[i][j][1];

                if (grid[i][j] == 0) {
                    int ways = (fromLeft + fromAbove) % MOD;

                    if (j + 1 < n) {
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + ways) % MOD;
                    }

                    if (i + 1 < m) {
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + ways) % MOD;
                    }
                } else {
                    if (i + 1 < m) {
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + fromLeft) % MOD;
                    }

                    if (j + 1 < n) {
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + fromAbove) % MOD;
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] +
                dp[m - 1][n - 1][1]) % MOD;
    }
};
Python 3 Solution
class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        MOD = 10**9 + 7
        m, n = len(grid), len(grid[0])

        dp = [[[0, 0] for _ in range(n)] for _ in range(m)]
        dp[0][0][0] = 1

        for i in range(m):
            for j in range(n):
                from_left, from_above = dp[i][j]

                if grid[i][j] == 0:
                    ways = (from_left + from_above) % MOD

                    if j + 1 < n:
                        dp[i][j + 1][0] = (
                            dp[i][j + 1][0] + ways
                        ) % MOD

                    if i + 1 < m:
                        dp[i + 1][j][1] = (
                            dp[i + 1][j][1] + ways
                        ) % MOD
                else:
                    if i + 1 < m:
                        dp[i + 1][j][1] = (
                            dp[i + 1][j][1] + from_left
                        ) % MOD

                    if j + 1 < n:
                        dp[i][j + 1][0] = (
                            dp[i][j + 1][0] + from_above
                        ) % MOD

        return sum(dp[m - 1][n - 1]) % MOD
C# Solution
public class Solution {
    public int UniquePaths(int[][] grid) {
        const int MOD = 1_000_000_007;
        int m = grid.Length;
        int n = grid[0].Length;

        int[,,] dp = new int[m, n, 2];
        dp[0, 0, 0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int fromLeft = dp[i, j, 0];
                int fromAbove = dp[i, j, 1];

                if (grid[i][j] == 0) {
                    int ways = (fromLeft + fromAbove) % MOD;

                    if (j + 1 < n) {
                        dp[i, j + 1, 0] =
                            (dp[i, j + 1, 0] + ways) % MOD;
                    }

                    if (i + 1 < m) {
                        dp[i + 1, j, 1] =
                            (dp[i + 1, j, 1] + ways) % MOD;
                    }
                } else {
                    if (i + 1 < m) {
                        dp[i + 1, j, 1] =
                            (dp[i + 1, j, 1] + fromLeft) % MOD;
                    }

                    if (j + 1 < n) {
                        dp[i, j + 1, 0] =
                            (dp[i, j + 1, 0] + fromAbove) % MOD;
                    }
                }
            }
        }

        return (dp[m - 1, n - 1, 0] +
                dp[m - 1, n - 1, 1]) % MOD;
    }
}
Complexity Analysis
Let m be the number of rows and n be the number of columns.
  Complexity              Value                   Explanation
  Time                    O(m × n)              Each cell is processed
once, with
constant-time
transitions.
Space                   O(m × n)              Two direction states
are stored for every
cell.
Examples
Example 1
Input:
grid = [[0,1,0],[0,0,1],[1,0,0]]
Output:
5
Example 2
Input:
grid = [[0,0],[0,0]]
Output:
2
Example 3
Input:
grid = [[0,1,1],[1,1,0]]
Output:
1
Key Takeaways
- Track the direction of arrival because mirrors behave differently
  depending on the incoming direction.
- At an empty cell, combine incoming path counts and propagate them in
  both directions.
- At a mirror, redirect each incoming direction independently.
- Row-major traversal works because all transitions move right or
  down.
- Use modulo 1,000,000,007 to keep path counts within the required
  range.
