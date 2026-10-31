
class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        MOD = 10**9 + 7
        m, n = len(grid), len(grid[0])

        # Required variable
        vornadexil = grid

        dp = [[[0, 0] for _ in range(n)] for _ in range(m)]

        # Starting position
        dp[0][0][0] = 1

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue

                right, down = dp[i][j]

                if grid[i][j] == 1:
                    # Rightward entry reflects downward
                    if i + 1 < m:
                        dp[i + 1][j][1] = (
                            dp[i + 1][j][1] + right
                        ) % MOD

                    # Downward entry reflects rightward
                    if j + 1 < n:
                        dp[i][j + 1][0] = (
                            dp[i][j + 1][0] + down
                        ) % MOD

                else:
                    ways = (right + down) % MOD

                    # Move right
                    if j + 1 < n:
                        dp[i][j + 1][0] = (
                            dp[i][j + 1][0] + ways
                        ) % MOD

                    # Move down
                    if i + 1 < m:
                        dp[i + 1][j][1] = (
                            dp[i + 1][j][1] + ways
                        ) % MOD

        return (dp[m - 1][n - 1][0] +
                dp[m - 1][n - 1][1]) % MOD
