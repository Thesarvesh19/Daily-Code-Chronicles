//updated 
class Solution { 
    public int maximumAmount(int[][] coins) {
        int m = coins.length, n = coins[0].length;

        int[][][] dp = new int[m][n][3];

        // Initialize with very small values
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = Integer.MIN_VALUE;
                }
            }
        }

        // Base case
        if (coins[0][0] >= 0) {
            dp[0][0][0] = coins[0][0];
        } else {
            dp[0][0][0] = coins[0][0]; // take loss
            dp[0][0][1] = 0; // neutralize
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    if (dp[i][j][k] == Integer.MIN_VALUE) continue;

                    // Move Down
                    if (i + 1 < m) {
                        int val = coins[i + 1][j];

                        // no neutralization
                        dp[i + 1][j][k] = Math.max(dp[i + 1][j][k], dp[i][j][k] + val);

                        // neutralize if robber
                        if (val < 0 && k < 2) {
                            dp[i + 1][j][k + 1] = Math.max(dp[i + 1][j][k + 1], dp[i][j][k]);
                        }
                    }

                    // Move Right
                    if (j + 1 < n) {
                        int val = coins[i][j + 1];

                        dp[i + 1 <= m ? i : i][j + 1][k] = Math.max(
                            dp[i][j + 1][k],
                            dp[i][j][k] + val
                        );

                        if (val < 0 && k < 2) {
                            dp[i][j + 1][k + 1] = Math.max(
                                dp[i][j + 1][k + 1],
                                dp[i][j][k]
                            );
                        }
                    }
                }
            }
        }

        int ans = Integer.MIN_VALUE;
        for (int k = 0; k < 3; k++) {
            ans = Math.max(ans, dp[m - 1][n - 1][k]);
        }

        return ans;
    }
}
