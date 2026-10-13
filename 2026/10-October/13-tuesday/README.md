# LeetCode 3727 - Maximum Alternating Sum of Squares

## Problem
Find the maximum alternating sum of squares by arranging the elements optimally.

## Approach
1. Sort the array in ascending order of the squares of its elements.
2. Subtract the squares of the smaller half of the elements.
3. Add the squares of the larger half of the elements.
4. Return the final sum.

## C++ Solution

```cpp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return 1LL * a * a < 1LL * b * b;
        });

        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long sq = 1LL * nums[i] * nums[i];

            if (i < n / 2)
                ans -= sq;
            else
                ans += sq;
        }

        return ans;
    }
};
```

## Complexity Analysis
- **Time Complexity:** O(n log n), due to sorting.
- **Space Complexity:** O(log n) auxiliary space for sorting.

## Key Concept
Sorting by square values helps place larger squares in the positive part of the alternating sum and smaller squares in the negative part, maximizing the result.
