#  Minimum Absolute Difference in Submatrices

##  Problem Statement
You are given an `m x n` integer matrix `grid` and an integer `k`.

For every contiguous `k x k` submatrix, compute the **minimum absolute difference between any two distinct values**.

Return a 2D array `ans` where:
- `ans[i][j]` represents the result for submatrix starting at `(i, j)`.

---

##  Approach

1. Iterate over all possible `k x k` submatrices.
2. For each submatrix:
   - Collect all elements.
   - Remove duplicates using `set`.
   - If only one unique value exists → answer is `0`.
   - Otherwise:
     - Sort the values.
     - Compute minimum difference between adjacent elements.

---

##  Complexity

- **Time Complexity:** `O((m - k + 1)(n - k + 1) * k^2 log(k^2))`
- **Space Complexity:** `O(k^2)`

---

##  Example

Input:

grid = [
[1, 3, 6],
[7, 2, 9],
[4, 8, 5]
]
k = 2


Output:

[
[1, 1],
[2, 1]
]


---

##  Key Takeaways

- Use of **set** to remove duplicates efficiently
- Sorting helps compute minimum adjacent differences
- Sliding window over matrix (brute-force style)

---

##  Language

- ✅ Python
