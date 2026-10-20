# 3886. Sum of Sortable Integers

## Problem
Given an integer array `nums` of length `n`, an integer `k` is sortable if `k` divides `n` and the array can be sorted in non-decreasing order by cyclically rotating each consecutive subarray of length `k` independently.

Return the sum of all sortable integers `k`.

## Approach
1. Calculate the prefix maximum array to track the maximum value before each position.
2. Calculate the suffix minimum array to track the minimum value from each position onward.
3. Use a prefix count of descending adjacent pairs to analyze each block.
4. Check only the divisors of `n`, since `k` must divide the array length.
5. Add every valid divisor to the answer.

## Complexity Analysis
- **Time Complexity:** `O(n√n)`
- **Space Complexity:** `O(n)`

## Language
C++

## Key Takeaway
Only divisors of the array length need to be considered. Prefix and suffix arrays help evaluate block boundaries efficiently.
