# 3348. Smallest Divisible Digit Product II

## Problem Statement

Given a numeric string `num` and an integer `t`, return the lexicographically smallest integer that is greater than or equal to `num`, contains no digit `0`, and whose digit product is divisible by `t`. If no such number exists, return `"-1"`.

## Approach

- Factorize `t` into its prime factors (`2`, `3`, `5`, and `7`).
- If any other prime factor exists, return `"-1"` since no digit can contribute it.
- Convert the required prime factors into the minimum set of digits.
- Traverse the number from right to left, trying to increase one digit while keeping the number as small as possible.
- Fill the remaining suffix with the smallest valid digits (`1`s followed by the required factor digits).
- If no valid number of the same length exists, construct the smallest valid number with one extra digit.

## Time Complexity

- **O(n + log t)**

## Space Complexity

- **O(n)**

## Tags

Greedy, Math, String, Number Theory
