class Solution:
    def maxPathScore(self, grid, k):
        m, n = len(grid), len(grid[0])
        k = min(k, m + n)

        dp = [[-1] * (k + 1) for _ in range(n)]
        next_dp = [[-1] * (k + 1) for _ in range(n)] 

        dp[0][0] = 0

        for i in range(m):
            for j in range(n):
                next_dp[j] = [-1] * (k + 1)

                if i == 0 and j == 0:
                    next_dp[0][0] = 0
                    continue

                val = grid[i][j]
                cost = 1 if val > 0 else 0

                for c in range(cost, k + 1):
                    prev_c = c - cost
                    mx = -1

                    if i > 0 and dp[j][prev_c] != -1:
                        mx = dp[j][prev_c]
                    if j > 0 and next_dp[j - 1][prev_c] != -1:
                        mx = max(mx, next_dp[j - 1][prev_c])

                    if mx != -1:
                        next_dp[j][c] = mx + val

            dp, next_dp = next_dp, dp

        return max(dp[n - 1])
