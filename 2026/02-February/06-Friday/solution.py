"""
3634. Minimum Removals to Balance Array

You are given an integer array nums and an integer k.

An array is considered balanced if the value of its maximum element
is at most k times the minimum element.

You may remove any number of elements from nums without making it empty.
Return the minimum number of elements to remove so that the remaining
array is balanced.
"""

class Solution:
    def minRemoval(self, nums, k):
        nums.sort()
        n = len(nums)

        left = 0
        max_window = 1

        for right in range(n):
            while nums[right] > nums[left] * k:
                left += 1
            max_window = max(max_window, right - left + 1)

        # Minimum removals needed
        return n - max_window
