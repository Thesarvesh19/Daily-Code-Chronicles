# Minimum Distance of Good Tuple (Java)
 
## Problem
Find minimum distance of indices (i, j, k) where values are equal.

## Optimization 
Distance simplifies to:
2 * (k - i)

## Steps
- Group indices by value
- For each group:
  - Check consecutive triplets
  - Compute minimum

## Complexity
Time: O(n)
Space: O(n)
