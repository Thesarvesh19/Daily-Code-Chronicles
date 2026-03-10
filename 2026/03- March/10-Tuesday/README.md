# Find All Possible Stable Binary Arrays

## Problem

You are given three positive integers:

zero – number of 0s  
one – number of 1s  
limit – maximum allowed consecutive identical numbers

A binary array is considered stable if:

1. It contains exactly `zero` number of 0s.
2. It contains exactly `one` number of 1s.
3. Every subarray with length greater than `limit` must contain both 0 and 1.

Return the total number of stable arrays. 

Since the answer can be very large, return it modulo **10^9 + 7**.

---

## Approach

We use **Dynamic Programming**.

Define:

dp[i][j][k]

Where:

- `i` = number of zeros used
- `j` = number of ones used
- `k` = last element in the array  
  - 0 → last element is zero  
  - 1 → last element is one

### Transition

If the last element is **0**:

dp[i][j][0] =
dp[i-1][j][0] + dp[i-1][j][1]
minus invalid cases where more than `limit` zeros appear consecutively.

If the last element is **1**:

dp[i][j][1] =
dp[i][j-1][0] + dp[i][j-1][1]
minus invalid cases where more than `limit` ones appear consecutively.

The subtraction removes sequences that would exceed the allowed limit.

### Initialization

- Arrays containing only zeros up to `limit` are valid.
- Arrays containing only ones up to `limit` are valid.

### Final Answer

result = dp[zero][one][0] + dp[zero][one][1]

---

## Complexity

Time Complexity

O(zero × one)

Space Complexity

O(zero × one)

---

## Implementations

- Python → `solution.py`
- C++ → `solution.cpp`
