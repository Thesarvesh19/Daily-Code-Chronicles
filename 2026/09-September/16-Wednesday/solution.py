class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        MOD = 10**9 + 7

        # dp[i][j] = number of ways using first i points
        # to create j non-overlapping segments.
        dp = [[0] * (k + 1) for _ in range(n)]

        for i in range(n):
            dp[i][0] = 1

        for i in range(1, n):
            for j in range(1, k + 1):
                # Don't use point i as the end of a new segment
                dp[i][j] = dp[i - 1][j]

                # Choose the starting point of the new segment.
                # Summing over all possible starts:
                for start in range(i):
                    dp[i][j] += dp[start][j - 1]
                    dp[i][j] %= MOD

        return dp[n - 1][k]
