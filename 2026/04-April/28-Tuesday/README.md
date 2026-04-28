# LeetCode 2033 - Minimum Operations to Make a Uni-Value Grid

## Problem
You are given a 2D grid and an integer x. In one operation, you can add or subtract x from any element.

Return the minimum number of operations to make all elements equal. If not possible, return -1.

---

## Approach

1. Flatten the grid into a 1D array.
2. Check feasibility:
   - All elements must have the same remainder when divided by x.
   - Otherwise, return -1.
3. Sort the array.
4. Choose the median element.
5. Compute total operations:
   - Sum of absolute differences divided by x.

---

## Why Median?
The median minimizes the sum of absolute differences, ensuring minimum operations.

---

## Complexity

- Time: O(n log n)
- Space: O(n)

---

## Supported Languages

- Python
- Java
- C++
- C
- JavaScript
- Go
- Kotlin
