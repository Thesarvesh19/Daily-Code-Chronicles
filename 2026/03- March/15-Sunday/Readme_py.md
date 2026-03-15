# Fancy Sequence API – Python

## Problem
Design an API that supports the following operations efficiently:

- append(val)
- addAll(inc)
- multAll(m)
- getIndex(idx)

All values are returned modulo **1e9 + 7**.

## Approach
Instead of updating all elements, maintain a **global affine transformation**:

value = stored_value * mul + add

Where:
- `mul` is cumulative multiplication
- `add` is cumulative addition

When appending:
We reverse the transformation using modular inverse.

## Complexity

| Operation | Time |
|----------|------|
| append | O(log MOD) |
| addAll | O(1) |
| multAll | O(1) |
| getIndex | O(1) |

## Key Idea
Lazy propagation of affine transformations.
