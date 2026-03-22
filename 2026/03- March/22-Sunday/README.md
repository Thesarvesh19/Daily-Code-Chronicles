#  Matrix Rotation Match

##  Problem
Given two `n x n` binary matrices `mat` and `target`, determine if `mat` can be rotated (in 90-degree increments) to match `target`.

---

##  Approach

We rotate the matrix up to **4 times**:
- 0° (original)
- 90°
- 180°
- 270°

After each rotation, we compare with `target`.

If any rotation matches → return `true`  
Otherwise → return `false`

---

##  Rotation Logic

To rotate a matrix 90° clockwise:

rotated[i][j] = matrix[n - j - 1][i]


---

##  Complexity

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n²)`

---

##  Example


Input:
mat = [[0,1],[1,0]]
target = [[1,0],[0,1]]

Output:
true
