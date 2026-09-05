# LeetCode 3904 - Smallest Stable Index II

## Approach

We need to find the first index where the difference between the maximum value in the prefix and the minimum value in the suffix is at most `k`.

### Steps

1. Create a `suffix_min` array where `suffix_min[i]` stores the minimum value from index `i` to the end.
2. Traverse the array from left to right while maintaining the maximum value seen so far (`prefix_max`).
3. At each index `i`, check:

   ```text
   prefix_max - suffix_min[i] <= k
   
