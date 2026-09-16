class Solution {
    public int numberOfSets(int n, int k) {
        final int MOD = 1_000_000_007;

        long[][] dp = new long[n][k + 1];

        // 0 segments can always be formed in exactly 1 way
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {

                // Don't use point i as the endpoint of a segment
                dp[i][j] = dp[i - 1][j];

                // Choose the starting point of the new segment
                for (int start = 0; start < i; start++) {
                    dp[i][j] = (dp[i][j] + dp[start][j - 1]) % MOD;
                }
            }
        }

        return (int) dp[n - 1][k];
    }
}
