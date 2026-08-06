# 3345. Smallest Divisible Digit Product I

## Problem
Given two integers `n` and `t`, find the smallest integer greater than or equal to `n` such that the product of its digits is divisible by `t`.

## Approach
- Start checking from `n`.
- Compute the product of the digits of the current number.
- If the product is divisible by `t`, return the number.
- Otherwise, increment the number and repeat.

## Algorithm
1. Initialize the current number as `n`.
2. Calculate the product of its digits.
3. If `product % t == 0`, return the current number.
4. Otherwise, increment the number by `1`.
5. Repeat until a valid number is found.

## Complexity
- **Time Complexity:** `O(log n)` on average (each digit-product computation takes `O(log n)`).
- **Space Complexity:** `O(1)`.

## Tags
`Math` `Brute Force` `Simulation`
