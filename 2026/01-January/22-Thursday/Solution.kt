class Solution {
    fun minimumPairRemoval(nums: IntArray): Int {
        val arr = nums.toMutableList()
        var ops = 0

        fun isSorted(): Boolean {
            for (i in 1 until arr.size) {
                if (arr[i] < arr[i - 1]) return false
            }
            return true
        }

        while (!isSorted()) {
            var minSum = Int.MAX_VALUE
            var idx = 0

            for (i in 0 until arr.size - 1) {
                val sum = arr[i] + arr[i + 1]
                if (sum < minSum) {
                    minSum = sum
                    idx = i
                }
            }

            arr[idx] = minSum
            arr.removeAt(idx + 1)
            ops++
        }

        return ops
    }
}
