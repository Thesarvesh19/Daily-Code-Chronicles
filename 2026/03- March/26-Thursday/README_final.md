# Grid Partition with Equal Sum

## Problem
Given a 2D grid of integers, determine whether it is possible to split the grid into two parts such that:

- The sum of elements in both parts is equal
- The split can be either horizontal or vertical

Additionally, in some cases, removing exactly one element from either side is allowed to balance the sums.

---

## Approach

We solve the problem in two steps:

### 1. Horizontal Split
- Traverse row by row
- Maintain:
  - `s1` → sum of top part
  - `s2` → sum of bottom part
- Use hashmaps to store frequency of elements in both parts

At each possible cut:
- If `s1 == s2` → valid partition found
- Otherwise:
  - Check if removing one element (difference) can balance the sums

---

### 2. Vertical Split
- Instead of writing separate logic, we **transpose the grid**
- Apply the same function again

This avoids code duplication and keeps the solution clean

---

## Key Idea

At every partition:
- Either sums match directly  
- Or can be made equal by removing one element equal to the difference

Hashmaps help us quickly check if such an element exists

---

## Complexity

Time: O(m * n)  
Space: O(m * n)

---

## Why This Works

- We process the grid only once per direction
- Efficient lookups using hashmap
- Avoid brute force checking of all partitions

---

## Implementation

- Python 

The same logic can be extended to other languages if needed
