# Concatenation of Consecutive Binary Numbers

##  Problem Statement

Given an integer `n`, return the decimal value of the binary string formed by concatenating the binary representations of `1` to `n` in order.

Since the answer may be very large, return it modulo `10^9 + 7`.

---

##  Approach

- Iterate from `1` to `n`
- Track the bit-length of each number
- If a number is a power of 2, increase the bit length
- Left shift the current result by the bit length
- Add the current number
- Apply modulo at each step to prevent overflow

---

##  Algorithm

1. Initialize:
   - `result = 0`
   - `length = 0`
2. For each number from `1` to `n`:
   - If number is power of 2 → increment bit length
   - Left shift result by `length`
   - Add current number
   - Take modulo `10^9 + 7`
3. Return result

---

## Complexity

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

