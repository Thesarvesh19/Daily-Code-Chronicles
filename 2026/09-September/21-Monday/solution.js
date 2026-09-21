/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var resultArray = function(nums, k) {
    const ans = new Array(k).fill(0);
    let dp = new Array(k).fill(0);

    for (const num of nums) {
        const mod = num % k;
        const newDp = new Array(k).fill(0);

        // Start a new subarray with only num
        newDp[mod]++;

        // Extend previous subarrays
        for (let r = 0; r < k; r++) {
            if (dp[r] > 0) {
                const newRemainder = (r * mod) % k;
                newDp[newRemainder] += dp[r];
            }
        }

        // Add subarrays ending at the current position
        for (let r = 0; r < k; r++) {
            ans[r] += newDp[r];
        }

        dp = newDp;
    }

    return ans;
};
