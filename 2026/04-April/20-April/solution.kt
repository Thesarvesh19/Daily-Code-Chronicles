// 2078. Two Furthest Houses With Different Colors
class Solution {
    fun maxDistance(colors: IntArray): Int {
        val n = colors.size
        var ans = 0

        for (i in 0 until n) {
            if (colors[i] != colors[0]) {
                ans = maxOf(ans, i)
            } 
            if (colors[i] != colors[n - 1]) {
                ans = maxOf(ans, n - 1 - i)
            }
        }

        return ans
    }
}
