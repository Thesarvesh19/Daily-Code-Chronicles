import java.util.*;

class Solution {
    public int maxPathScore(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length; 
        k = Math.min(k, m + n);

        int[][] dp = new int[n][k + 1];
        int[][] next_dp = new int[n][k + 1];

        for (int[] row : dp) Arrays.fill(row, -1);
        dp[0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(next_dp[j], -1);

                if (i == 0 && j == 0) {
                    next_dp[0][0] = 0;
                    continue;
                }

                int val = grid[i][j];
                int cost = val > 0 ? 1 : 0;

                for (int c = cost; c <= k; c++) {
                    int prev_c = c - cost;
                    int mx = -1;

                    if (i > 0 && dp[j][prev_c] != -1) {
                        mx = dp[j][prev_c];
                    }
                    if (j > 0 && next_dp[j - 1][prev_c] != -1) {
                        mx = Math.max(mx, next_dp[j - 1][prev_c]);
                    }

                    if (mx != -1) {
                        next_dp[j][c] = mx + val;
                    }
                }
            }
            int[][] temp = dp;
            dp = next_dp;
            next_dp = temp;
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = Math.max(ans, dp[n - 1][c]);
        }
        return ans;
    }
}
