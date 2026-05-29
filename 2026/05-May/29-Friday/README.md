# LeetCode 3300 - Minimum Element After Replacement With Digit Sum

## Problem Description

You are given an array of positive integers `nums`.

Replace each element with the sum of its digits and return the minimum value among the resulting elements.

### Example

Input:
nums = [10, 12, 13, 14]

Digit sums:
10 -> 1
12 -> 3
13 -> 4
14 -> 5

Output:
1

## Approach

For every number in the array:

1. Calculate the sum of its digits.
2. Keep track of the smallest digit sum encountered.
3. Return the minimum digit sum.

## Algorithm

1. Initialize a variable `ans` with a large value.
2. Iterate through each number in the array.
3. Compute its digit sum using modulo (`%`) and division (`/`).
4. Update `ans` with the minimum value.
5. Return `ans`.

## Complexity Analysis

- Time Complexity: O(n × d)
  - n = number of elements
  - d = number of digits in a number

- Space Complexity: O(1)


## Key Concept

The main idea is to transform every number into its digit sum and then find the smallest transformed value.
