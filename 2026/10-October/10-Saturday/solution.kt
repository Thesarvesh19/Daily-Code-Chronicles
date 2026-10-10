
class Solution {
    fun minSumSquareDiff(
        nums1: IntArray,
        nums2: IntArray,
        k1: Int,
        k2: Int
    ): Long {
        var k = k1.toLong() + k2
        val diff = IntArray(nums1.size) {
            kotlin.math.abs(nums1[it] - nums2[it])
        }

        if (diff.sumOf { it.toLong() } <= k) return 0L

        var left = 0
        var right = diff.maxOrNull() ?: 0

        while (left < right) {
            val mid = left + (right - left) / 2
            var ops = 0L

            for (d in diff) {
                ops += maxOf(0, d - mid)
            }

            if (ops <= k) {
                right = mid
            } else {
                left = mid + 1
            }
        }

        for (i in diff.indices) {
            if (diff[i] > left) {
                k -= (diff[i] - left).toLong()
                diff[i] = left
            }
        }

        for (i in diff.indices) {
            if (k == 0L) break
            if (diff[i] == left && left > 0) {
                diff[i]--
                k--
            }
        }

        var ans = 0L
        for (d in diff) {
            ans += d.toLong() * d
        }

        return ans
    }
}
