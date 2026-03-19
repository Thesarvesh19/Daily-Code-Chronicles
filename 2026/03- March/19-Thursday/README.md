# 3212. Count Submatrices With Equal Frequency of X and Y

##  Problem Summary

Given a 2D grid containing:
- 'X'
- 'Y'
- '.' 

Count the number of submatrices that:
1. Include the top-left cell `(0,0)`
2. Have equal number of 'X' and 'Y'
3. Contain at least one 'X'

---

##  Approach

###  Transformation
Convert grid values:
- 'X' → +1
- 'Y' → -1
- '.' → 0

Now:
- Equal number of X and Y ⇒ sum = 0
- At least one X ⇒ track count of X separately

---

###  Prefix Sum Technique

We compute:
- `prefix_sum[i][j]`: sum of values from (0,0) to (i,j)
- `prefix_x[i][j]`: count of 'X' from (0,0) to (i,j)

---

### ✅ Valid Submatrix Condition

For each cell `(i, j)`:
- `prefix_sum[i][j] == 0`
- `prefix_x[i][j] > 0`

---

##  Complexity

- Time: **O(m × n)**
- Space: **O(m × n)**

---

##  Example

Input:

X Y .
Y . .


Converted:

1 -1 0
-1 0 0


Valid submatrices:
- (0,1)
- (1,0)
- (1,1)

Output:

3
