"""
3719. Longest Balanced Subarray I
--------------------------------
A subarray is balanced if the number of distinct even numbers
equals the number of distinct odd numbers.
"""

class Solution: 
    def longestBalanced(self, nums):
        n = len(nums)
        max_len = 0

        for i in range(n):
            even_set = set()
            odd_set = set()

            for j in range(i, n):
                if nums[j] % 2 == 0:
                    even_set.add(nums[j])
                else:
                    odd_set.add(nums[j])

                if len(even_set) == len(odd_set):
                    max_len = max(max_len, j - i + 1)

        return max_len
