# Special Positions in a Binary Matrix

## Problem
Given an `m x n` binary matrix `mat`, return the number of **special positions** in the matrix.

A position `(i, j)` is called **special** if:
- `mat[i][j] == 1`
- All other elements in **row `i`** are `0`
- All other elements in **column `j`** are `0`

Rows and columns are **0-indexed**.

---

## Examples

### Example 1
Input:

mat = [[1,0,0],
[0,0,1],
[1,0,0]]


Output:

1


Explanation:  
Position `(1,2)` is special because it is `1` and all other elements in its row and column are `0`.

---

### Example 2
Input:

mat = [[1,0,0],
[0,1,0],
[0,0,1]]


Output:

3


Explanation:  
Positions `(0,0)`, `(1,1)`, and `(2,2)` are special.

---

## Constraints
- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 100`
- `mat[i][j]` is either `0` or `1`

---

## Approach

A position `(i, j)` is special if:
- `mat[i][j] == 1`
- The **sum of row `i` is 1**
- The **sum of column `j` is 1**

Steps:
1. Compute the sum of each row.
2. Compute the sum of each column.
3. Traverse the matrix:
   - If `mat[i][j] == 1`
   - and `row_sum[i] == 1`
   - and `col_sum[j] == 1`
   - then increment the count.

---

## Algorithm
1. Let `m` be number of rows and `n` be number of columns.
2. Compute `row_sum` array storing number of `1`s in each row.
3. Compute `col_sum` array storing number of `1`s in each column.
4. Traverse all cells:
   - If a cell contains `1` and its row sum and column sum are both `1`, it is a special position.
5. Return the total count.

---

## Complexity Analysis

**Time Complexity:**  

O(m × n)

We traverse the matrix a constant number of times.

**Space Complexity:**  

O(m + n)

For storing row and column sums.

---

## Python Implementation

```python
from typing import List

class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])

        row_sum = [sum(row) for row in mat]
        col_sum = [sum(mat[i][j] for i in range(m)) for j in range(n)]

        count = 0

        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1 and row_sum[i] == 1 and col_sum[j] == 1:
                    count += 1

        return count
