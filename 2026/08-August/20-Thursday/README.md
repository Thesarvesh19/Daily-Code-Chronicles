# LeetCode 3069 - Distribute Elements Into Two Arrays I

## Problem

Given an integer array `nums`, create two arrays `arr1` and `arr2`:

- Initially, `arr1 = [nums[0]]` and `arr2 = [nums[1]]`.
- For every element `nums[i]` from index `2` onward:
  - If the last element of `arr1` is greater than the last element of `arr2`, append `nums[i]` to `arr1`.
  - Otherwise, append `nums[i]` to `arr2`.
- Return the array formed by concatenating `arr1` and `arr2`.

## Approach

1. Create two arrays `a` and `b`.
2. Put the first element in `a` and the second element in `b`.
3. Iterate through the remaining elements.
4. Compare the last elements of `a` and `b`.
5. Append the current element to the appropriate array.
6. Finally, concatenate `a` and `b`.

## Python

```python
class Solution:
    def resultArray(self, nums):
        a = [nums[0]]
        b = [nums[1]]

        for i in range(2, len(nums)):
            if a[-1] > b[-1]:
                a.append(nums[i])
            else:
                b.append(nums[i])

        return a + b
