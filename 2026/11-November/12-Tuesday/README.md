# 3411. Maximum Length of Subarray With Equal Product

## Problem Statement
Given an array of positive integers `nums`, find the maximum length of a subarray such that the product of its elements is equal to the product of its LCM and GCD.

## Approach
- Iterate through all possible subarrays using two nested loops.
- For each subarray, calculate its product, GCD, and LCM.
- Check whether the product is equal to the LCM multiplied by the GCD.
- If the condition holds, update the maximum length.
- Return the maximum length found.

## Python Solution
```python
class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0

        for i in range(n):
            for j in range(i, n):
                prod = 1
                lcm = 1
                gcd_val = 1

                for k in range(i, j + 1):
                    prod *= nums[k]
                    gcd_val = math.gcd(gcd_val, nums[k])
                    lcm = math.lcm(lcm, nums[k])

                if prod == lcm * gcd_val:
                    ans = max(ans, j - i + 1)

        return ans
```

## Complexity Analysis
- **Time Complexity:** O(n³ × log M), where n is the array length and M is the maximum element.
- **Space Complexity:** O(1) auxiliary space.

## Topics
- Array
- Math
- GCD
- LCM
- Brute Force
