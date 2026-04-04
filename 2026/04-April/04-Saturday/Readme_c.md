# Decode Slanted Ciphertext (C)

## Problem
Decode a string encoded using a slanted transposition cipher.

## Approach
- Compute columns = n / rows
- Dynamically allocate matrix
- Fill matrix row-wise
- Traverse diagonals
- Store result in dynamically allocated string
- Trim trailing spaces and null-terminate

## Complexity
- Time: O(n)
- Space: O(n)
