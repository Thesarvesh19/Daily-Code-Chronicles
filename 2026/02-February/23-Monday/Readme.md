# Check If a String Contains All Binary Codes of Size K

## Problem Statement

Given a binary string `s` and an integer `k`, return true if every binary code of length `k` is a substring of `s`. Otherwise, return false.

A binary code of length `k` means all possible combinations of 0 and 1 of length `k`.

Total possible binary codes = 2^k

---

## Approach

1. Total possible binary substrings of length k is 2^k.
2. Use a sliding window of size k.
3. Store each substring in a HashSet (Java) or set (Python).
4. If the number of unique substrings becomes equal to 2^k, return true.
5. If we finish scanning and do not reach 2^k, return false.
6. Add an early optimization:
   If (length of s - k + 1) < 2^k, return false immediately.

---

## Why This Works

- We check every substring of length k.
- We track unique substrings.
- If we collect all possible combinations, then the condition is satisfied.

---

## Time Complexity

O(n)

Where n is the length of string s.

Each character is processed once using sliding window.

---

## Space Complexity

O(2^k)

In the worst case, we may store all possible binary codes of length k.

---

## Languages Implemented

- Java
- Python
