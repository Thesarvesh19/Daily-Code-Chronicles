Updated documentation
# Grid Partition with Equal Sum

## Problem
Given an m x n grid of positive integers, determine if it is possible to make one horizontal or vertical cut such that:

- Both sections are non-empty
- Their sums are equal OR can be made equal by removing at most one cell
- The remaining section must stay connected

---

## Approach

1. Try all possible horizontal cuts
2. Try all possible vertical cuts (by transposing grid)
3. Maintain:
   - Running sums (s1, s2)
   - Frequency maps for both parts
4. If sums are not equal:
   - Find difference
   - Check if a cell with that value exists in the larger section
   - Ensure removing it does not break connectivity

---

## Key Observations

- If section is 2D → always connected after removal
- If section is 1D → removal must be from edge

---

## Complexity

- Time: O(m × n)
- Space: O(m × n)

---

