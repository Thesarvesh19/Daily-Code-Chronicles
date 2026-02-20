# Special Binary String - Python Solution

## Problem Statement
A special binary string:
1. Contains equal number of '1's and '0's.
2. Every prefix has at least as many '1's as '0's.

We can swap two consecutive special substrings.
Return the lexicographically largest possible string. 

---

## Approach

The algorithm works as follows:

1. Traverse the string while maintaining a balance counter.
2. When balance becomes zero, we identify a special substring.
3. Recursively solve the inner portion of that substring.
4. Collect all processed substrings.
5. Sort them in descending order.
6. Join them together to get the final answer.

This guarantees the lexicographically maximum result.

---

## Time Complexity

O(n^2 log n)

- Recursive splitting may take quadratic time.
- Sorting contributes a log factor.
- Works efficiently for n ≤ 50.

---

## Space Complexity

O(n)

Due to recursion stack and temporary substring storage.
