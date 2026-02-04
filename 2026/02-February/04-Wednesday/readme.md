# Maximum Sum Trionic Subarray

This repository contains a Java solution to compute the **maximum sum of a trionic subarray**.

##  What is a Trionic Subarray?

A trionic subarray consists of **three consecutive parts**:
1. Strictly increasing
2. Strictly decreasing
3. Strictly increasing

Each part must contain **at least one element**, and the subarray must be contiguous.

##  Goal

Given an integer array, find the **maximum possible sum** of any trionic subarray.
If no valid trionic subarray exists, return the minimum possible `long` value.

##  Approach

- Traverse the array in a single pass
- Detect increasing → decreasing → increasing patterns
- Calculate the sum efficiently by extending from both sides
- Keep track of the maximum sum found

## Complexity

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)



