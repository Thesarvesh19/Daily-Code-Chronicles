# LeetCode 2784 - Check if Array is Good

## Problem Statement
Given an integer array `nums`, return `true` if the array is good, otherwise return `false`.

A good array satisfies:
- It contains numbers from `1` to `n-1`
- Every number appears exactly once
- The number `n-1` appears exactly twice

## Approach
1. Sort the array.
2. Check whether the last two elements are equal to `n-1`.
3. Verify that the first `n-2` elements are exactly `1,2,3,...,n-2`.
4. Return `true` if all conditions are satisfied, otherwise `false`.

## Algorithm
- Sort the array.
- Validate the last two values.
- Iterate through the remaining elements and compare with expected values.

## Complexity Analysis
- Time Complexity: `O(n log n)`
- Space Complexity: `O(1)` (excluding sorting space)

