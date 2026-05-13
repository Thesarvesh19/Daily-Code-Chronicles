# 1674. Minimum Moves to Make Array Complementary

## Problem
Given an integer array `nums` and an integer `limit`, return the minimum number of moves required to make the array complementary.

A move consists of replacing any element of the array with any integer between `1` and `limit`.

---

## Approach
We process pairs:
- `nums[i]`
- `nums[n - 1 - i]`

Using a difference array:
- `0 moves` if pair sum already equals target
- `1 move` if target sum can be achieved by changing one element
- `2 moves` otherwise

We sweep all possible sums from `2` to `2 * limit` and compute the minimum moves.

---

## Time Complexity
- **O(n + limit)**

## Space Complexity
- **O(limit)**
