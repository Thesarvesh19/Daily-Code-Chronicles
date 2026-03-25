# Equal Sum Grid Partition I

## Problem Statement

Given an m x n grid of positive integers, determine whether it is possible to make either:

- one horizontal cut, or
- one vertical cut

such that:

- both resulting sections are non-empty
- the sum of elements in both sections is equal
 
Return true if such a partition exists, otherwise false.

---

## Approach

1. Compute the total sum of the grid.
2. If the total sum is odd, return false.
3. Otherwise, target sum = total / 2.

### Horizontal Cut
- Iterate through rows and keep adding row sums.
- If prefix sum equals target, return true.

### Vertical Cut
- Compute column sums.
- Iterate through columns and keep adding column sums.
- If prefix sum equals target, return true.

---

## Complexity

- Time Complexity: O(m * n)
- Space Complexity: O(n)

---

## Example

Input:
grid = [[1,4],[2,3]]

Output:
true

Explanation:
A horizontal cut results in two parts with equal sum (5 each).

---

## Notes

- Ensure both partitions are non-empty.
- Efficient prefix sum approach avoids brute force.
