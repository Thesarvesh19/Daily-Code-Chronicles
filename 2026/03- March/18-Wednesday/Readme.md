# Count Submatrices with Top-Left Element and Sum ≤ k

## 🧩 Problem
Given a 2D grid and an integer k, count the number of submatrices that:
- Include the top-left element (0,0)
- Have sum ≤ k

---

## 💡 Approach

Since every submatrix must start at (0,0), we only consider all possible bottom-right corners (i, j).

We compute the sum efficiently using:
- Column prefix sums (`colSum`)
- Row-wise accumulation (`rowPrefix`)

---

## ⚡ Algorithm

1. Initialize `colSum` array
2. Iterate through rows
3. Update column sums
4. Maintain prefix sum for each row
5. Count if sum ≤ k

---

## ⏱ Complexity

- Time: O(m × n)
- Space: O(n)

---

## 🧪 Example

Input:

grid = [[7,6,3],[6,6,1]]
k = 18


Output:

4


---

## 🚀 Languages Implemented

- C
- Python
- Java
