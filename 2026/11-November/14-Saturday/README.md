# LeetCode 3364 - Minimum Positive Sum Subarray

## Problem Description
Given an integer array `nums` and two integers `l` and `r`, find the minimum positive sum of a subarray whose length is between `l` and `r` (inclusive).

Return the minimum positive sum. If no such subarray exists, return `-1`.

## Approach: Brute Force

1. Iterate through each index as the starting position of a subarray.
2. Initialize the subarray sum to `0`.
3. Expand the subarray by iterating through subsequent elements.
4. Calculate the current subarray length and sum.
5. If the length is between `l` and `r` and the sum is positive, update the minimum sum.
6. Stop expanding when the subarray length exceeds `r`.
7. Return `-1` if no valid positive sum is found; otherwise, return the minimum sum.

## C++ Solution

```cpp
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];

                int len = j - i + 1;

                if (len >= l && len <= r && sum > 0) {
                    ans = min(ans, sum);
                }

                if (len > r) {
                    break;
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
```

## Complexity Analysis

- **Time Complexity:** O(n × r), where `n` is the size of the array and `r` is the maximum allowed subarray length.
- **Space Complexity:** O(1), as only a constant amount of extra space is used.

## Key Concepts
- Arrays
- Subarrays
- Nested Loops
- Prefix Sum Basics
- Brute Force

## Difficulty
Easy

## Language
C++
