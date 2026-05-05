# LeetCode 61 - Rotate List

## Problem
Rotate a linked list to the right by k places.

## Approach
1. Compute the length of the list.
2. Connect tail to head to form a circular list.
3. Find the new tail at (length - k % length - 1).
4. Break the circle and return new head.

## Complexity
- Time: O(n)
- Space: O(1)
