# 2946. Matrix Similarity After Cyclic Shifts

## Problem
Given a matrix, perform cyclic shifts on rows:
- Even rows → shift left
- Odd rows → shift right

Repeat this process k times.

Return true if the matrix becomes same as original.

---

## Approach

Instead of performing k operations, we reduce it:

effective shift = k % number_of_columns

If shift is 0, matrix remains unchanged.

Otherwise:
- For even rows → left shift
- For odd rows → right shift

Compare shifted row with original row.

---

## Complexity

Time: O(m * n)  
Space: O(n)

---

## Key Insight

If k % n == 0 → matrix always remains same
