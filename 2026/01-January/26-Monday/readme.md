# Minimum Absolute Difference

This project finds all pairs of numbers in an array that have the minimum absolute difference.

## Problem
Given an array of distinct integers, return all pairs `[a, b]` such that:
- `a < b`
- `b - a` is the smallest possible difference among all pairs

## Approach
- Sort the array
- Compare adjacent elements
- Track the minimum difference
- Collect all pairs with that difference

## Example
Input:
[4, 2, 1, 3]

Output:
[[1, 2], [2, 3], [3, 4]]

## Language
- Python
