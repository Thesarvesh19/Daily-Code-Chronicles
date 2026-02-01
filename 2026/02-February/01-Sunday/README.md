# Divide Array Into Subarrays With Minimum Cost

## Problem
You are given an integer array `nums` of length `n`.

The cost of a subarray is its first element.  
You must divide the array into **3 disjoint contiguous subarrays** and return the **minimum possible sum of their costs**.

---

## Approach
- The first subarray always starts at index `0`, so its cost is `nums[0]`.
- Choose two split points for the start of the second and third subarrays.
- For every valid split, compute:

nums[0] + nums[i] + nums[j]

- Return the minimum value obtained.

---

## Complexity
- Time: O(n²)  
- Space: O(1)

---

## Example
Input:
nums = [1, 2, 3, 12]


Output:
6


Explanation:
[1] | [2] | [3, 12]
Cost = 1 + 2 + 3 = 6


---

## Solution (Python)

```python
class Solution:
    def minimumCost(self, nums):
        n = len(nums)
        ans = float('inf')

        for i in range(1, n - 1):
            for j in range(i + 1, n):
                ans = min(ans, nums[0] + nums[i] + nums[j])

        return ans
