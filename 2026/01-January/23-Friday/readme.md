# Minimum Pair Removal to Sort Array

## 📌 Problem Statement
You are given an array of integers.  
In one operation, you must select the **adjacent pair with the minimum sum** (choosing the leftmost in case of ties) and replace it with their sum.

Return the **minimum number of operations** required to make the array **non-decreasing**.

---

## 🧠 Approach
- Maintain adjacent pair sums in a sorted data structure
- Always merge the pair with the smallest sum
- Track inversions dynamically to know when the array becomes non-decreasing
- Update neighbors efficiently after each merge

This simulates the problem constraints exactly as required.

---

## ⚙️ Implementation Details
- Language: **C++**
- Data Structures Used:
  - `set` for ordered pair sums
  - Arrays for previous & next indices (linked-list simulation)
- Time Complexity: **O(n log n)**
- Space Complexity: **O(n)**

---

## ✅ Example
**Input**
