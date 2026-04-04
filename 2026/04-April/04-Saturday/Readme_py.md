# Decode Slanted Ciphertext

## Problem
Decode a string encoded using a slanted transposition cipher.

## Approach
- Compute number of columns = n / rows
- Build matrix row-wise
- Traverse diagonals
- Remove trailing spaces

## Complexity
- Time: O(n)
- Space: O(n)
