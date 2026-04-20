# 2078. Two Furthest Houses With Different Colors (C)

## Problem Understanding
We need the largest index gap where colors are not equal.

## Approach Breakdown
- Traverse from left to right
- For each position:
  - Compare with first element
  - Compare with last element
- Maintain a running maximum

## Low-Level Consideration
Since C has no built-in max, comparisons are done manually.

## Complexity
Time Complexity: O(n)  
Space Complexity: O(1)
