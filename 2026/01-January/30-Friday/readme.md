# Minimum Cost to Convert String II (LeetCode 2977)

##  Problem Summary

You are given two strings `source` and `target` of equal length.  
You are also given transformation rules that allow converting one substring into another at a certain cost.

Each operation:
- Converts a **whole substring**
- Must be **disjoint** from other operations,  
  OR applied **multiple times on the same exact range**

The goal is to convert `source` into `target` with **minimum total cost**, or return `-1` if impossible.

---

##  Key Idea

1. **Substring transformations can be chained**, so we compute the minimum cost to convert one substring into another using graph shortest paths.
2. Only substrings that appear in the transformation rules matter — this keeps the solution fast.
3. Use **Dynamic Programming** to split the string into valid, non-overlapping segments.

---

##  Algorithm Used

- **Floyd–Warshall** to compute minimum transformation costs for substrings of the same length.
- **Dynamic Programming** to compute the minimum cost to convert the full string.

---

## Complexity

- **Time Complexity:**  
  `O(K³ + N · K)`  
  where `K ≤ 100` (number of transformation rules) and `N ≤ 1000` (string length)

- **Space Complexity:**  
  `O(K² + N)`

---

##  Result

- Passes **all test cases**
- Efficient enough for the largest inputs
- Fully respects problem constraints

---

## Implementation

See `solution.py` for the complete implementation.
