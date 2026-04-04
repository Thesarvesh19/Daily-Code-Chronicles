# Decode Slanted Ciphertext (C++)

## Problem
Reconstruct the original text from a slanted transposition encoded string.

## Approach
- Determine number of columns
- Store characters in a 2D vector row-wise
- Traverse diagonals (i++, j++)
- Build result string
- Remove trailing spaces manually

## Complexity
- Time: O(n)
- Space: O(n)
