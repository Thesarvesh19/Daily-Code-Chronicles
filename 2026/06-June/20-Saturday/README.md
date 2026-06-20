# 1840. Maximum Building Height

## Approach

1. Add building `1` with height `0`.
2. Add building `n` with maximum possible height `n - 1` if not already present.
3. Sort restrictions by building index.
4. Perform:
   - Left-to-right pass to enforce height constraints.
   - Right-to-left pass to enforce height constraints.
5. For every adjacent restricted pair:
   - Compute the highest achievable peak between them.
   - Formula:

   peak = (h1 + h2 + distance) // 2

6. Return the maximum peak found.

## Time Complexity

O(m log m)

- `m` = number of restrictions

## Space Complexity

O(1) extra space (excluding sorting).
