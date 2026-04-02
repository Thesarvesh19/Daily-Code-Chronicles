#updated
class Solution:
    def maximumAmount(self, coins):
        m, n = len(coins), len(coins[0])

        # dp[i][j][k]
        dp = [[[-float('inf')] * 3 for _ in range(n)] for _ in range(m)]

        # Base case
        if coins[0][0] >= 0:
            dp[0][0][0] = coins[0][0]
        else:
            dp[0][0][0] = coins[0][0]
            dp[0][0][1] = 0

        for i in range(m):
            for j in range(n):
                for k in range(3):
                    if dp[i][j][k] == -float('inf'):
                        continue

                    # Move Down
                    if i + 1 < m:
                        val = coins[i + 1][j]

                        # no neutralization
                        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + val)

                        # neutralize
                        if val < 0 and k < 2:
                            dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k])

                    # Move Right
                    if j + 1 < n:
                        val = coins[i][j + 1]

                        dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k] + val)

                        if val < 0 and k < 2:
                            dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k])

        return max(dp[m - 1][n - 1])
