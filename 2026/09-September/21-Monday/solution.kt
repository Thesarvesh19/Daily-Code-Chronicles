class Solution {
    fun resultArray(nums: IntArray, k: Int): IntArray {
        val ans = IntArray(k)
        var dp = IntArray(k)

        for (num in nums) {
            val mod = num % k
            val newDp = IntArray(k)

            // Start a new subarray with only num
            newDp[mod]++

            // Extend previous subarrays
            for (r in 0 until k) {
                if (dp[r] > 0) {
                    val newRemainder = (r * mod) % k
                    newDp[newRemainder] += dp[r]
                }
            }

            // Add subarrays ending at current position
            for (r in 0 until k) {
                ans[r] += newDp[r]
            }

            dp = newDp
        }

        return ans
    }
}
