# 2840. Check if Strings Can Be Made Equal With Operations II

## Problem

You are given two strings `s1` and `s2` of the same length.
 
You can perform an operation any number of times:
- Choose two indices `i` and `j` such that `j - i` is even
- Swap characters at those indices

Return `true` if you can make `s1` equal to `s2`, otherwise return `false`.

---

## Key Idea

You can only swap characters between:
- even indices with even indices
- odd indices with odd indices

So, characters at even positions stay within even positions,
and characters at odd positions stay within odd positions.

---

## Approach

1. Count frequency of characters at:
   - even indices
   - odd indices

2. Do this for both strings

3. Compare:
   - even frequencies must match
   - odd frequencies must match

If both match, return true.

---

## Example

Input:
s1 = "abcdba"  
s2 = "cabdab"  

Output:
true

---

## Complexity

Time Complexity: O(n)  
Space Complexity: O(1)

---

## Summary

We do not need to simulate swaps.

We just check if:
- even index characters match in frequency
- odd index characters match in frequency
