class Solution {
    public int xorAfterQueries(int[] nums, int[][] queries) {
        long MOD = 1000000007;

        for (int[] q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            for (int i = l; i <= r; i += k) {
                nums[i] = (int)((nums[i] * 1L * v) % MOD);
            }
        }

        int result = 0;
        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
}
