# Lexicographically Smallest Generated String

## Problem
You are given two strings:
- `str1` (length n) consisting of 'T' and 'F' 
- `str2` (length m)

You need to construct a string `word` of length `n + m - 1` such that:

- If `str1[i] == 'T'`, then substring `word[i...i+m-1] == str2`
- If `str1[i] == 'F'`, then substring `word[i...i+m-1] != str2`

Return the **lexicographically smallest** valid string. If impossible, return `""`.

---

## Approach

1. Create a result array of size `n + m - 1`.
2. Maintain a boolean array `modifiable` to track positions that can be changed.

### Step 1: Apply 'T' constraints
- Force substrings to match `str2`
- If conflict occurs, return empty string

### Step 2: Fill remaining positions
- Fill all unassigned positions with `'a'` to keep result lexicographically smallest

### Step 3: Handle 'F' constraints
- If any substring matches `str2` when it should not:
  - Find the rightmost modifiable position
  - Change it to `'b'`
  - If no such position exists, return empty string

---

## Complexity

- Time Complexity: O(n * m)
- Space Complexity: O(n + m)

---
