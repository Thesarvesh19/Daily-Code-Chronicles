class Solution {
    fun check(nums: IntArray): Boolean {
        var count = 0
        val n = nums.size

        for(i in nums.indices){
            if(nums[i] > nums[(i+1)%n])
                count++
        }

        return count <= 1
    }
}
