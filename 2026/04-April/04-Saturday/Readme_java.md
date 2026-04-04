# Decode Slanted Ciphertext (Java)

## Problem
Given an encoded string formed using a slanted transposition cipher and the number of rows, reconstruct the original string.

## Approach
- Compute number of columns using `n / rows`
- Fill a 2D matrix row-wise using the encoded string
- Traverse diagonally starting from each column of the first row
- Build the result string
- Remove trailing spaces

## Complexity 
- Time: O(n)
- Space: O(n)
