# 2615. Sum of Distances

## Problem Summary

Given an integer array `nums`, compute an array `arr` such that:

arr[i] = sum of |i - j| for all j where nums[j] == nums[i] and j != i

If no such index exists, arr[i] = 0.

---

## Approach

### Key Idea

Instead of computing pairwise distances (O(n²)), we optimize using:

- Grouping indices by value
- Prefix sum technique for fast distance computation

---

### Steps

1. Group all indices having the same value
2. For each group:
   - Sort indices (if not already sorted)
   - Compute prefix sums
3. For each index:
   - Left contribution:
     ```
     i * count_left - sum_left
     ```
   - Right contribution:
     ```
     sum_right - i * count_right
     ```
4. Combine both contributions

---

## Complexity

| Language | Time Complexity | Space Complexity |
|--------|----------------|------------------|
| Python | O(n) | O(n) |
| Java   | O(n) | O(n) |
| C      | O(n log n) | O(n) |

---

## Implementations

- Python → `solution.py`
- Java → `solution.java`
- C → `solution.c`

---

## Example

Input:

nums = [1,3,1,1,2]


Output:

[5,0,3,4,0]


---

## Key Concepts

- Prefix Sum
- HashMap / Grouping
- Index distance optimization

---
