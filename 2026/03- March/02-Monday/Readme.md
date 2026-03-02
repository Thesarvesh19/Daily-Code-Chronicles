# Minimum Swaps to Arrange a Binary Grid

## Problem Statement

Given an n x n binary grid, in one step you can choose two adjacent rows and swap them.

A grid is valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps required to make the grid valid, or -1 if it is impossible.

## Approach

For a grid to be valid:

For row i, all elements from column i+1 to n-1 must be 0.

This means each row must have at least (n - i - 1) trailing zeros.

Algorithm:

1. Count trailing zeros for every row.
2. For each position i:
   - Find a row at or below index i that has enough trailing zeros.
   - Move that row to position i using adjacent swaps.
3. If no such row exists, return -1.
4. Count total swaps performed.

## Complexity

Time Complexity: O(n^2)  
Space Complexity: O(n)

## Example

Input:
[[0,0,1],
 [1,1,0],
 [1,0,0]]

Output:
3

## Implementation

Refer to solution.py for the complete implementation.
