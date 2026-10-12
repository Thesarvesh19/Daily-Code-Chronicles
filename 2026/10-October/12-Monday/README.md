# 2897. Apply Operations on Array to Maximize Sum of Squares

## Problem
Given an integer array `nums` and an integer `k`, perform operations to maximize the sum of squares of `k` numbers formed using the available set bits. Return the maximum sum modulo `10^9 + 7`.

## Approach
1. Count the number of set bits at each bit position across all elements.
2. Construct the largest possible number by using every bit position that has an available set bit.
3. Decrease the count of each bit used.
4. Repeat this process `k` times and add the square of each constructed number to the answer.
5. Return the answer modulo `10^9 + 7`.

## C++ Solution
```cpp
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> cnt(31, 0);

        for (int num : nums) {
            for (int i = 0; i < 31; i++) {
                if ((num >> i) & 1)
                    cnt[i]++;
            }
        }

        long long ans = 0;

        for (int j = 0; j < k; j++) {
            long long num = 0;

            for (int i = 0; i < 31; i++) {
                if (cnt[i] > 0) {
                    num |= (1LL << i);
                    cnt[i]--;
                }
            }

            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};
```

## Complexity Analysis
- **Time Complexity:** `O(31 × (n + k))`, effectively `O(n + k)`.
- **Space Complexity:** `O(31)`, which is `O(1)` auxiliary space.

## Key Concept
**Greedy Algorithm + Bit Manipulation**

The solution greedily combines available set bits to create the largest possible numbers, maximizing the sum of their squares.
