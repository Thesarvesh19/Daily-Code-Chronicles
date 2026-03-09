class Solution {

    private static final int MOD = 1000000007;
    private Long[][][][] memo;
    private int limit;

    public int numberOfStableArrays(int zero, int one, int limit) {
        this.limit = limit;
        memo = new Long[zero + 1][one + 1][3][limit + 1];
        return (int) dfs(zero, one, 2, 0);
    }

    private long dfs(int z, int o, int last, int streak) {
        if (z == 0 && o == 0) return 1;

        if (memo[z][o][last][streak] != null)
            return memo[z][o][last][streak];

        long ans = 0;

        if (z > 0) {
            if (last != 0)
                ans += dfs(z - 1, o, 0, 1);
            else if (streak < limit)
                ans += dfs(z - 1, o, 0, streak + 1);
        }

        if (o > 0) {
            if (last != 1)
                ans += dfs(z, o - 1, 1, 1);
            else if (streak < limit)
                ans += dfs(z, o - 1, 1, streak + 1);
        }

        ans %= MOD;
        return memo[z][o][last][streak] = ans;
    }
}
