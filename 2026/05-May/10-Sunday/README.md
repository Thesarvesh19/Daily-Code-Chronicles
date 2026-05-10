# 2770. Maximum Number of Jumps to Reach the Last Index

## Problem Statement

You are given a 0-indexed integer array `nums` and an integer `target`.

You are initially positioned at index `0`.  
In one step, you can jump from index `i` to index `j` if:

- `i < j`
- `abs(nums[j] - nums[i]) <= target`

Return the maximum number of jumps needed to reach the last index.

If it is not possible to reach the last index, return `-1`.

---


