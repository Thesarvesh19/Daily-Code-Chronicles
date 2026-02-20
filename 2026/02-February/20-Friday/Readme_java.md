# Special Binary String - Java Solution

## Problem Statement
A special binary string:
1. Has equal number of '1's and '0's.
2. Every prefix contains at least as many '1's as '0's.

We can swap two consecutive special substrings.
The goal is to obtain the lexicographically largest possible string.

--- 

## Approach

The solution is based on recursion and sorting.

1. Traverse the string and keep track of balance:
   - Increment balance for '1'
   - Decrement balance for '0'

2. Whenever balance becomes 0, we found a valid special substring.

3. Recursively process the inner part of that substring.

4. Store all such processed substrings.

5. Sort them in descending lexicographical order.

6. Concatenate them to get the final result.

This greedy strategy ensures the largest lexicographical arrangement.

---

## Time Complexity

O(n^2 log n)

- Recursive decomposition takes O(n^2) in worst case.
- Sorting substrings adds log n factor.
- Since n ≤ 50, this is efficient.

---

## Space Complexity

O(n)

Used for recursion stack and substring storage.
