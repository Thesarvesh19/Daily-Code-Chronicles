# LeetCode 3942 — Python, C++, and Java Solutions

## Problem
**3942. Minimum Operations to Sort a Permutation**

## Approach
The solution finds the position of `0` and checks whether the array can be sorted by traversing it in either circular direction. It then calculates the possible operation counts and returns the minimum valid result.

### Algorithm
1. Find the index of `0` in the array.
2. Check the array in the forward circular direction.
3. Check the array in the backward circular direction.
4. Calculate the minimum number of operations for each valid direction.
5. Return the minimum result, or `-1` if neither direction is valid.

## Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

