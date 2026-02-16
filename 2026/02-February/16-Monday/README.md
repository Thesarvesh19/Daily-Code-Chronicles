# Reverse Bits

## Problem Statement
Reverse bits of a given 32-bit unsigned integer.

--- 

## Approach

We iterate through all 32 bits of the integer:

1. Shift result left to make space.
2. Extract last bit of n using (n & 1).
3. Add extracted bit to result.
4. Shift n right to process next bit.
5. Repeat 32 times.

---

## Time Complexity
O(1) — since loop runs exactly 32 times.

## Space Complexity
O(1) — constant extra space used.

---

