# 3129. Find All Possible Stable Binary Arrays I

## Problem
You are given three integers:

- zero → number of 0s
- one → number of 1s
- limit → maximum allowed consecutive identical numbers

A binary array is **stable** if:

1. It contains exactly `zero` zeros.
2. It contains exactly `one` ones.
3. Any subarray with length greater than `limit` must contain both `0` and `1`.

This effectively means **no more than `limit` consecutive identical elements are allowed**.

Return the number of such stable arrays modulo **1e9 + 7**.

---

## Approach

We solve this using **Dynamic Programming with Memoization**.

### State Definition


dfs(z, o, last, streak)


Where:

- `z` = remaining zeros
- `o` = remaining ones
- `last` = last placed element
- `streak` = current consecutive count of the last element

### Transitions

We can place:

**0**
- if zeros remain
- and consecutive 0 count ≤ limit

**1**
- if ones remain
- and consecutive 1 count ≤ limit

### Base Case


if z == 0 and o == 0
return 1


### Memoization

We cache states to avoid recomputation.

---

## Complexity

Time Complexity


O(zero * one * limit)


Space Complexity


O(zero * one * limit)


---
