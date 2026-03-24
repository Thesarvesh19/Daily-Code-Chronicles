# Construct Product Matrix

## Problem Description

Given a 2D integer matrix `grid` of size `n x m`, return a matrix `p` where each element `p[i][j]` is the product of all elements in `grid` except `grid[i][j]`.

All values must be taken modulo **12345**.

---

## Example

### Input

grid = [[1, 2],
[3, 4]]


### Output

[[24, 12],
[ 8, 6]]


---

## Approach

We cannot use division because:
- Modulo operation is involved
- There may be zero values in the matrix

### Steps

1. Flatten the 2D matrix into a 1D array
2. Build a **prefix product array**
   - `prefix[i]` stores product of all elements before index `i`
3. Build a **suffix product array**
   - `suffix[i]` stores product of all elements after index `i`
4. Compute result:

result[i] = (prefix[i] * suffix[i]) % 12345

5. Convert the result back into a 2D matrix

---

## Complexity

- Time Complexity: `O(n * m)`
- Space Complexity: `O(n * m)`

---

## Implementation

### Python
```python
class Solution:
 def constructProductMatrix(self, grid):
     MOD = 12345
     n, m = len(grid), len(grid[0])
     
     arr = []
     for row in grid:
         arr.extend(row)
     
     size = len(arr)
     
     prefix = [1] * size
     for i in range(1, size):
         prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD
     
     suffix = [1] * size
     for i in range(size - 2, -1, -1):
         suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD
     
     result = [(prefix[i] * suffix[i]) % MOD for i in range(size)]
     
     res = []
     idx = 0
     for i in range(n):
         row = []
         for j in range(m):
             row.append(result[idx])
             idx += 1
         res.append(row)
     
     return res
