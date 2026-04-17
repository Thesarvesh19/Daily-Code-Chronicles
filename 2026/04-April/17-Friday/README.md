# Minimum Absolute Distance Between Mirror Pairs

## Problem Statement
You are given an integer array nums.

A mirror pair is a pair of indices (i, j) such that:
- 0 <= i < j < nums.length
- reverse(nums[i]) == nums[j] 

Return the minimum absolute distance between such pairs.
If no such pair exists, return -1.

## Approach
- Iterate through the array
- Maintain a hashmap storing reversed values and their indices
- For each number:
  - Check if it exists in hashmap
  - If yes, compute distance
  - Store its reversed value in hashmap

## Time Complexity
O(n)

## Space Complexity
O(n)

## Key Insight
Instead of checking reverse(nums[i]) == nums[j], we store reversed values beforehand to allow constant-time lookup.

## Example
Input:
nums = [12,21,45,33,54]

Output:
1
