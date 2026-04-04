# Decode Slanted Ciphertext

## Problem
You are given a string that was encoded using a slanted matrix and a number of rows. You need to find the original string.

## Idea
- First, find how many columns are in the matrix.
- Fill the matrix row by row using the encoded string.
- Read the matrix diagonally from top-left to bottom-right.
- Remove extra spaces at the end.

## Steps
1. Find columns = length of string / rows
2. Fill matrix row-wise
3. Traverse diagonally
4. Build result string
5. Remove trailing spaces

## Complexity
- Time: O(n)
- Space: O(n)

## Languages
Solutions are provided in:
- Python
- Java
- Kotlin
- C++
- C
