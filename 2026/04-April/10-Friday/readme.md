# Minimum Distance Between Three Equal Elements

## Problem
Given an integer array nums, find a tuple (i, j, k) such that:
- i, j, k are distinct indices
- nums[i] == nums[j] == nums[k]

The distance is defined as:
abs(i - j) + abs(j - k) + abs(k - i)

Return the minimum possible distance. If no such tuple exists, return -1.

---

## Key Observation

For any i < j < k:

distance = (j - i) + (k - j) + (k - i)
         = 2 * (k - i)

So the problem reduces to:
Find three equal elements with minimum (k - i)

---

## Approach

1. Store indices of each number
2. For each number:
   - If it appears at least 3 times
   - Check every consecutive group of 3 indices
   - Compute 2 * (last index - first index)
3. Return the minimum value

---

## Complexity

Time Complexity: O(n^2) worst case  
Space Complexity: O(n)

---

## Example

Input:
[1,2,1,1,3]

Indices of 1:
[0,2,3]

Distance:
2 * (3 - 0) = 6

Output:
6
