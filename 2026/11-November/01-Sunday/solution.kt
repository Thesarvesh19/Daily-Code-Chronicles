
class Solution {
    fun minMoves(nums: IntArray): Int {
        val minVal = nums.minOrNull()!!
        val sum = nums.sum() 

        return sum - nums.size * minVal
    }
}
