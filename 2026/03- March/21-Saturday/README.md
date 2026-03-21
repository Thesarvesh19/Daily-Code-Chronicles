#  Reverse Submatrix

##  Problem Statement
You are given an `m x n` integer matrix `grid`, and three integers `x`, `y`, and `k`.

- `(x, y)` represents the top-left corner of a square submatrix.
- `k` represents the size of the submatrix.
 
###  Task
Reverse the submatrix **vertically** (i.e., flip rows within the submatrix).

Return the updated matrix.

---

##  Approach

- We only need to iterate through **half of the rows** of the submatrix.
- For each row `i`, swap it with its corresponding row from the bottom:
  

row i ↔ row (k - 1 - i)


- Perform the swap column by column within the submatrix range.

---

##  Complexity

- **Time Complexity:** `O(k^2)`
- **Space Complexity:** `O(1)` (in-place modification)

---

##  Implementations

- ✅ Java (`solution.java`)
- ✅ Python (`solution.py`)

---

##  Example

Input:

grid = [
[1,2,3],
[4,5,6],
[7,8,9]
]
x = 0, y = 0, k = 2


Output:

[
[4,5,3],
[1,2,6],
[7,8,9]
]
