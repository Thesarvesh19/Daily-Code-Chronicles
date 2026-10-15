class Solution {
    fun sumCounts(nums: List<Int>): Int {
        var ans = 0
        val n = nums.size

        for (i in 0 until n) {
            val s = mutableSetOf<Int>()

            for (j in i until n) {
                s.add(nums[j])
                ans += s.size * s.size
            }
        }

        return ans
    }
}
