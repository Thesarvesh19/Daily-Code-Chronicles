class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k) {
        vector<int> ans(k, 0);
        vector<int> dp(k, 0);

        for (int num : nums) {
            int mod = num % k;
            vector<int> newDp(k, 0);

            // Start a new subarray with only num
            newDp[mod]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRemainder = (r * mod) % k;
                    newDp[newRemainder] += dp[r];
                }
            }

            // Add subarrays ending at current position
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};
