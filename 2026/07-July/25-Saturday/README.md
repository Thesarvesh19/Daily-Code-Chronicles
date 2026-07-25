# 3536. Maximum Product of Two Digits

## Overview

This repository contains solutions for **LeetCode 3536 – Maximum Product of Two Digits** in multiple programming languages.

The approach scans every digit of the given integer, keeps track of the two largest digits encountered, and returns their product. Since only a few variables are used, the solution is both efficient and memory-friendly.

## Algorithm

1. Initialize two variables to store the largest and second-largest digits.
2. Extract digits one by one using modulo (`% 10`).
3. Update the two maximum digits whenever a larger digit is found.
4. Continue until all digits have been processed.
5. Return the product of the two largest digits.

## Correctness

- Every digit of the number is examined exactly once.
- The algorithm always maintains the largest and second-largest digits seen so far.
- After processing all digits, these two values represent the maximum possible pair of digits.
- Their product is therefore the maximum product obtainable.

## Complexity Analysis

- **Time Complexity:** `O(log n)`
  - The algorithm processes each digit exactly once.

- **Space Complexity:** `O(1)`
  - Only a constant amount of extra memory is used.

## Languages Included

- Python
- Java
- C
- C++
- C#
- Go
- Kotlin

## Advantages

- Simple and easy to understand
- Single-pass solution
- Constant extra space
- Optimal time complexity
- Suitable for large input values

## Conclusion

This solution efficiently computes the maximum product of any two digits in an integer by maintaining the two largest digits during a single traversal. It achieves optimal performance with linear processing over the digits and constant auxiliary space.
