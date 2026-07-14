class Solution {
    private static final int MOD = 1_000_000_007;

    private int n;
    private int[] nums;
    private int[][][] memo;

    public int subsequencePairCount(int[] nums) {
        this.nums = nums;
        this.n = nums.length;

        memo = new int[n + 1][201][201];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 200; j++) {
                java.util.Arrays.fill(memo[i][j], -1);
            }
        }

        return dfs(0, 0, 0);
    }

    private int dfs(int index, int gcd1, int gcd2) {
        if (index == n) {
            return (gcd1 != 0 && gcd1 == gcd2) ? 1 : 0;
        }

        if (memo[index][gcd1][gcd2] != -1) {
            return memo[index][gcd1][gcd2];
        }

        long ans = 0;

        // Skip current element
        ans += dfs(index + 1, gcd1, gcd2);

        // Put into first subsequence
        int nextGcd1 = (gcd1 == 0) ? nums[index] : gcd(gcd1, nums[index]);
        ans += dfs(index + 1, nextGcd1, gcd2);

        // Put into second subsequence
        int nextGcd2 = (gcd2 == 0) ? nums[index] : gcd(gcd2, nums[index]);
        ans += dfs(index + 1, gcd1, nextGcd2);

        memo[index][gcd1][gcd2] = (int) (ans % MOD);
        return memo[index][gcd1][gcd2];
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
}
