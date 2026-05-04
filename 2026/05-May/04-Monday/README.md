# 48. Rotate Image

## 🧩 Problem
Given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You must rotate the image **in-place**, meaning you cannot use another matrix.

---

## 💡 Approach 

The rotation can be done in two steps:

1. **Transpose the matrix**
   - Convert rows into columns by swapping `matrix[i][j]` with `matrix[j][i]`.

2. **Reverse each row**
   - This completes the 90° clockwise rotation.

---

## 🔁 Example

### Input

matrix = [
[1,2,3],
[4,5,6],
[7,8,9]
]


### Output

[
[7,4,1],
[8,5,2],
[9,6,3]
]


---

## ⏱ Complexity

- **Time Complexity:** O(n²)
- **Space Complexity:** O(1) (in-place)

---

## 🧑‍💻 Solutions

### Python
```python
class Solution:
    def rotate(self, matrix):
        n = len(matrix)
        
        # Transpose
        for i in range(n):
            for j in range(i, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        # Reverse rows
        for row in matrix:
            row.reverse()
C++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse rows
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
Java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;

        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // Reverse rows
        for (int[] row : matrix) {
            for (int i = 0, j = n - 1; i < j; i++, j--) {
                int temp = row[i];
                row[i] = row[j];
                row[j] = temp;
            }
        }
    }
}



- `solution.cpp`

Add C++ solution for LeetCode 48 with in-place matrix rotation approach
