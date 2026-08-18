# LeetCode 3471 - Find the Largest Almost Missing Integer

## Problem

You are given an integer array `nums` and an integer `k`.

An integer `x` is called **almost missing** if it appears in exactly one subarray of length `k` within `nums`.

Return the **largest almost missing integer**. If no such integer exists, return `-1`.

---

## Approach

We examine every subarray of length `k`.

### Steps

1. Iterate through all possible subarrays of length `k`.
2. Use a `Set` to store the distinct elements in the current subarray.
3. For every distinct element, increment its frequency.
4. After processing all subarrays:
   - An element is **almost missing** if its frequency is exactly `1`.
   - Find the maximum such element.
5. If no element has frequency `1`, return `-1`.

### Why use a Set?

If a number occurs multiple times inside the same subarray, that subarray should still count only **once** for that number.

---

## Example

### Input

```text
nums = [3, 9, 2, 1, 7]
k = 3
