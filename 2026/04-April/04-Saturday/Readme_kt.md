# Decode Slanted Ciphertext (Kotlin) 

## Problem
Decode a string encoded with a slanted transposition cipher using a fixed number of rows.

## Approach
- Calculate columns = length / rows
- Construct matrix row-wise
- Traverse diagonals from top row
- Append characters to result
- Trim trailing spaces

## Complexity
- Time: O(n)
- Space: O(n)
