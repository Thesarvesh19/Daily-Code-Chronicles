class Solution:
    def minOperations(self, grid, x):
        nums = [num for row in grid for num in row]
        nums.sort()

        base = nums[0] % x
        for num in nums:
            if num % x != base:
                return -1 

        median = nums[len(nums) // 2]
        return sum(abs(num - median) // x for num in nums)
