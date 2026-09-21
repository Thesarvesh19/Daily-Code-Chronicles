class Solution {
    public int[] resultArray(int[] nums, int k) {
        int[] ans = new int[k];
        int[] dp = new int[k];

        for (int num : nums) {
            int mod = num % k;
            int[] newDp = new int[k];

            // Start a new subarray with only num
            newDp[mod]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRemainder = (r * mod) % k;
                    newDp[newRemainder] += dp[r];
                }
            }

            // Add all subarrays ending at current position
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
}
