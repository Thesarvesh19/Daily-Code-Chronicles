class Solution:
    def champagneTower(self, poured, query_row, query_glass):
        dp = [[0.0] * (r + 1) for r in range(query_row + 1)]
        dp[0][0] = poured

        for r in range(query_row):
            for c in range(len(dp[r])):
                if dp[r][c] > 1:
                    overflow = (dp[r][c] - 1) / 2.0
                    dp[r + 1][c] += overflow
                    dp[r + 1][c + 1] += overflow
                    dp[r][c] = 1.0

    
        return min(1.0, dp[query_row][query_glass])
