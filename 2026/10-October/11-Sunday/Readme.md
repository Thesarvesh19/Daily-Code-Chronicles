# LeetCode 2778 - Sum of Squares of Special Elements

## Problem Statement
Given a 0-indexed integer array `nums`, find the sum of the squares of all special elements.

An element is special if its **1-based index divides the length of the array**.

## Approach
1. Find the length of the array, `n`.
2. Iterate through all 1-based indices from `1` to `n`.
3. If `n % i == 0`, the element at index `i - 1` is special.
4. Add its square to the answer.
5. Return the final sum.

## C++ Solution
```cpp
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                ans += nums[i - 1] * nums[i - 1];
            }
        }

        return ans;
    }
};
```

## Example
**Input:** `nums = [1,2,3,4]`

**Output:** `21`

**Explanation:** The special indices are 1, 2, and 4.

Sum = \(1^2 + 2^2 + 4^2 = 21\).

## Complexity Analysis
- **Time Complexity:** O(n), as we iterate through the array once.
- **Space Complexity:** O(1), as we use only a constant amount of extra space.

## Topics
- Array
- Basic Math
- Implementation
