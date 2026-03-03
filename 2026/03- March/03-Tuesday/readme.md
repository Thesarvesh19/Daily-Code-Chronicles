# Find Kth Bit in Nth Binary String

## Problem Description

Given two positive integers n and k, a binary string Sn is formed as follows:

S1 = "0"

Si = Si-1 + "1" + reverse(invert(Si-1)) for i > 1
 
Return the kth bit in Sn.

Constraints:
1 <= n <= 20
1 <= k <= 2^n - 1

---

## Approach

Observations:

1. Length of Sn = 2^n - 1
2. Middle position = 2^(n-1)
3. Structure:
   Sn = S(n-1) + "1" + reverse(invert(S(n-1)))

Cases:

- If k equals middle index → return '1'
- If k is in left half → same as S(n-1, k)
- If k is in right half:
  - Mirror position to left side
  - Recursively find value
  - Invert the bit

We avoid constructing the full string because it grows exponentially.

Time Complexity: O(n)
Space Complexity: O(n) recursion stack

---

## Implementations Included

- Python
- Java
- Kotlin
- C

All implementations use the same recursive mirror logic.
