# LeetCode 2567 - Minimum Score by Changing Two Elements

## Problem Statement
Given an integer array `nums`, modify at most two elements to minimize the difference between the largest and smallest elements in the array. Return the minimum possible difference.

## Approach
1. Sort the array in ascending order.
2. Since we can change at most two elements, consider the three possible ways to eliminate the extremes:
   - Remove the two smallest elements from consideration.
   - Remove the smallest and largest elements from consideration.
   - Remove the two largest elements from consideration.
3. Calculate the range for each possibility.
4. Return the minimum of the three ranges.

## Python Solution

```python
class Solution:
    def minimizeSum(self, nums: list[int]) -> int:
        nums.sort()
        n = len(nums)

        return min(
            nums[n - 1] - nums[2],
            nums[n - 2] - nums[1],
            nums[n - 3] - nums[0]
        )
