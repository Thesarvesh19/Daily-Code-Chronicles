# Closest Equal Element Queries

## Problem Statement

You are given a circular array `nums` and an array `queries`.

For each query index `i`, find the minimum distance between index `queries[i]` and any other index `j` such that:

- `nums[j] == nums[queries[i]]`
- Distance is calculated in a circular manner

If no such index exists, return `-1` for that query.

Return an array where each element corresponds to the answer for each query.

---

## Example

Input:
nums = [1,3,1,4,1,3,2]  
queries = [0,3,5]

Output:
[2, -1, 3]

---

## Approach

### Python
- Use a hashmap to store indices of each value
- For each query:
  - Use binary search to find nearest equal index
  - Compute circular distance

Time Complexity: O(n + q log n)  
Space Complexity: O(n)

---

### C
- Store (value, index) pairs
- Sort by value
- Group equal values and compute nearest neighbors
- Answer queries using precomputed left and right arrays

Time Complexity: O(n log n)  
Space Complexity: O(n)

---

## Key Concept

Circular distance:
distance = min(abs(i - j), n - abs(i - j))
