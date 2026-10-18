class Solution {
    private static final int MOD = 1_000_000_007;
    private long[][] comb;

    private long solve(java.util.List<Integer> nums) {
        int n = nums.size();

        if (n <= 2) {
            return 1;
        }

        int root = nums.get(0);
        java.util.List<Integer> left = new java.util.ArrayList<>();
        java.util.List<Integer> right = new java.util.ArrayList<>();

        for (int i = 1; i < n; i++) {
            int x = nums.get(i);

            if (x < root) {
                left.add(x);
            } else {
                right.add(x);
            }
        }

        long waysLeft = solve(left);
        long waysRight = solve(right);

        long ways = comb[n - 1][left.size()];
        ways = ways * waysLeft % MOD;
        ways = ways * waysRight % MOD;

        return ways;
    }

    public int numOfWays(int[] nums) {
        int n = nums.length;

        comb = new long[n + 1][n + 1];

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        java.util.List<Integer> list = new java.util.ArrayList<>();

        for (int x : nums) {
            list.add(x);
        }

        return (int) ((solve(list) - 1 + MOD) % MOD);
    }
}
