// Minimum Absolute Distance Between Mirror Pairs

class Solution {
    fun minMirrorPairDistance(nums: IntArray): Int {
        val map = HashMap<Int, Int>()
        var ans = Int.MAX_VALUE

        for (j in nums.indices) {
            val num = nums[j]
 
            if (map.containsKey(num)) {
                ans = minOf(ans, j - map[num]!!)
            }

            val rev = reverse(num)
            map[rev] = j
        }

        return if (ans == Int.MAX_VALUE) -1 else ans
    }

    private fun reverse(x: Int): Int {
        var num = x
        var rev = 0
        while (num > 0) {
            rev = rev * 10 + num % 10
            num /= 10
        }
        return rev
    }
}
