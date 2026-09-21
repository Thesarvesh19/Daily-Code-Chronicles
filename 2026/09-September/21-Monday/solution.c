/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int k, int* returnSize) {
    int* ans = (int*)calloc(k, sizeof(int));
    int* dp = (int*)calloc(k, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int mod = nums[i] % k;

        int* newDp = (int*)calloc(k, sizeof(int));

        // Start a new subarray with only nums[i]
        newDp[mod]++;

        // Extend previous subarrays
        for (int r = 0; r < k; r++) {
            if (dp[r] > 0) {
                int newRemainder = (r * mod) % k;
                newDp[newRemainder] += dp[r];
            }
        }

        // Add subarrays ending at the current position
        for (int r = 0; r < k; r++) {
            ans[r] += newDp[r];
        }

        free(dp);
        dp = newDp;
    }

    free(dp);

    *returnSize = k;
    return ans;
}
