# XOR After Range Multiplication Queries

## Problem

You are given an array `nums` and a list of queries.

Each query is of the form:
[l, r, k, v]

For each query:
- Start from index l
- Update elements at positions: l, l + k, l + 2k, ... while index <= r
- Multiply each selected element by v
- Take modulo (10^9 + 7)

After processing all queries, return the XOR of all elements in the array.

---

## Approach

A direct brute force solution will be too slow because it may take O(n * q) time.

To optimize, we use square root decomposition.

### Key Idea

1. Divide queries into two types:
   - Small k (k < sqrt(n))
   - Large k (k >= sqrt(n))

2. For large k:
   - Number of updates is small
   - Process directly using a loop

3. For small k:
   - Group queries by remainder (l % k)
   - Build sequences like:
     r, r+k, r+2k ...
   - Compress indices into a smaller array

4. Use a difference array:
   - Multiply at start index
   - Multiply inverse at end index
   - Apply prefix multiplication

5. Update original array using computed values

6. Finally compute XOR of all elements

---

## Complexity

Time Complexity: O(n * sqrt(n))  
Space Complexity: O(n)

---

## Notes

- Modular inverse is used to remove multiplication effect after range
- Index compression is required because indices are not continuous
- This avoids Time Limit Exceeded errors

---

## Example

Input:
nums = [2,3,1,5,4]  
queries = [[1,4,2,3],[0,2,1,2]]

Output:
31

---

## Summary

- Brute force is too slow
- Optimized using grouping and math
- Efficient for large constraints
