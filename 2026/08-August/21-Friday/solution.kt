import kotlin.math.*

class Solution {
    fun findKthSmallest(coins: IntArray, k: Int): Long {
        val n = coins.size

        fun gcd(a: Long, b: Long): Long {
            var x = a
            var y = b
            while (y != 0L) {
                val temp = x % y
                x = y
                y = temp
            }
            return x
        }

        fun lcm(a: Long, b: Long): Long {
            return a / gcd(a, b) * b
        }

        fun count(x: Long): Long {
            var total = 0L

            for (mask in 1 until (1 shl n)) {
                var multiple = 1L
                var bits = 0
                var valid = true

                for (i in 0 until n) {
                    if ((mask and (1 shl i)) != 0) {
                        bits++
                        multiple = lcm(multiple, coins[i].toLong())

                        if (multiple > x) {
                            valid = false
                            break
                        }
                    }
                }

                if (!valid) continue

                val cnt = x / multiple

                if (bits % 2 == 1)
                    total += cnt
                else
                    total -= cnt
            }

            return total
        }

        var left = 1L
        var right = coins.minOrNull()!!.toLong() * k

        while (left < right) {
            val mid = left + (right - left) / 2

            if (count(mid) >= k)
                right = mid
            else
                left = mid + 1
        }

        return left
    }
}
