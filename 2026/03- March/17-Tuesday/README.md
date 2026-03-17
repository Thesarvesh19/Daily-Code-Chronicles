# Largest Submatrix With Rearrangements (LeetCode 1727)

##  Problem
Given a binary matrix, you can rearrange columns in any order.

Return the largest possible area of a submatrix consisting only of 1's.

---

##  Approach

1. Convert matrix into heights:
   - Each cell stores consecutive 1s above it.

2. For each row:
   - Sort heights in descending order (simulate column rearrangement)
   - Compute max area using:
     ```
     area = height × width
     ```

---

##  Complexity

- Time: O(m × n log n)
- Space: O(1)

---

##  Example

Input:

[[0,0,1],
[1,1,1],
[1,0,1]]


Output:

4


---

##  Files

- `solution.py` → Python implementation
- `solution.java` → Java implementation
- `solution.c` → C implementation

---

##  Key Insight

Sorting each row allows optimal column rearrangement, turning the problem into a histogram-based max area calculation.
