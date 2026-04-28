class Solution {
    fun minOperations(grid: Array<IntArray>, x: Int): Int {
        val nums = mutableListOf<Int>()

        for (row in grid) {
            for (num in row) {
                nums.add(num)
            }
        } 

        nums.sort()

        val base = nums[0] % x
        for (num in nums) {
            if (num % x != base) return -1
        }

        val median = nums[nums.size / 2]
        var ops = 0

        for (num in nums) {
            ops += Math.abs(num - median) / x
        }

        return ops
    }
}
