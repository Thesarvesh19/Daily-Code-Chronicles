class Solution {
    public int zigZagArrays(int n, int l, int r) {
        int MOD = 1_000_000_007;
        r -= l; // Normalize range to 0-indexed
        int[] dp = new int[r + 1];
        
        // Base case: 1 way to pick any starting number
        for (int i = 0; i <= r; i++) {
            dp[i] = 1;
        }
        
        for (int i = 1; i < n; i++) {
            int pre = 0, pre2;
            if ((i & 1) == 1) { // Up
                for (int v = 0; v <= r; v++) {
                    pre2 = pre + dp[v];
                    dp[v] = pre;
                    pre = pre2 % MOD;
                }
            } else { // Down
                for (int v = r; v >= 0; v--) {
                    pre2 = pre + dp[v];
                    dp[v] = pre;
                    pre = pre2 % MOD;
                }
            }
        }
        
        int res = 0;
        for (int v : dp) {
            res = (res + v) % MOD;
        }
        
        return (res * 2) % MOD; // Multiply by 2 for both zigzag directions
    }
}
