class Solution:
    def minElement(self, nums):
        def digit_sum(x):
            return sum(int(d) for d in str(x))
        
        return min(digit_sum(x) for x in nums)
