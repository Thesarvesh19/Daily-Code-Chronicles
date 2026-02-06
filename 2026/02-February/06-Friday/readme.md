# Minimum Removals to Balance Array

This repository contains a Python solution for the LeetCode problem  
**"Minimum Removals to Balance Array"**.
 
## Problem Summary
An array is considered **balanced** if the maximum element is at most  
`k` times the minimum element.

You are allowed to remove elements from the array (without making it empty)
and your task is to find the **minimum number of removals** required to make
the array balanced.

##  Approach Used
- First, the array is sorted.
- A sliding window (two-pointer technique) is used to find the largest
  contiguous subarray that satisfies the balance condition.
- The answer is calculated by subtracting the size of this valid subarray
  from the total number of elements.

##  Complexity
- **Time Complexity:** O(n log n) due to sorting
- **Space Complexity:** O(1) extra space

##  Why This Works Well
- Efficient for large inputs
- Clean and easy to understand
- Uses a standard two-pointer pattern


