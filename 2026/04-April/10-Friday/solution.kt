class Solution {
    fun minimumDistance(nums: IntArray): Int {
        val map = mutableMapOf<Int, MutableList<Int>>()

        for (i in nums.indices) {
            map.getOrPut(nums[i]) { mutableListOf() }.add(i)
        }

        var ans = Int.MAX_VALUE

        for (list in map.values) { 
            for (i in 0 until list.size - 2) {
                ans = minOf(ans, 2 * (list[i + 2] - list[i]))
            }
        }

        return if (ans == Int.MAX_VALUE) -1 else ans
    }
}
