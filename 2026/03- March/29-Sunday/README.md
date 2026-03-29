# Check if Strings Can be Made Equal With Operations I

## Problem
You are given two strings `s1` and `s2` of length 4.

You can perform an operation:
- Choose indices `i` and `j` such that `j - i = 2`
- Swap the characters at those indices

Return `true` if you can make `s1` equal to `s2`, otherwise return `false`.

---

## Key Idea

We can only swap:
- Index 0 with 2 (even positions)
- Index 1 with 3 (odd positions)

So:
- Characters at even indices can only move among even indices
- Characters at odd indices can only move among odd indices

---

## Approach

1. Take characters at:
   - Even indices → (0, 2)
   - Odd indices → (1, 3)

2. Sort both groups for both strings

3. Compare:
   - Even parts must be equal
   - Odd parts must be equal

If both match → return `true`  
Else → return `false`

---

## Example

### Example 1
Input:
s1 = "abcd"  
s2 = "cdab"  

Output:
true  

### Example 2
Input:
s1 = "abcd"  
s2 = "dacb"  

Output:
false  

---

## Complexity

- Time Complexity: O(1)
- Space Complexity: O(1)

---

## Files

- `solution.java` → Java implementation  
- `solution.kt` → Kotlin implementation  

---

## Summary

Only positions with the same parity (even or odd) can be swapped.  
So we just need to check if both groups match.
