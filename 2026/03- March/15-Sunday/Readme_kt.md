 # Fancy Sequence API – Kotlin Implementation

## Problem Description

Design a sequence that supports the following operations:

- append(val)
- addAll(inc)
- multAll(m)
- getIndex(idx)

All outputs must be computed modulo **1e9 + 7**.

---

## Optimized Approach

Instead of modifying every element in the list, maintain two global variables:

- mul
- add

Each value in the sequence can be computed as:

value = stored_value * mul + add

When appending:

We reverse the current transformation using a modular inverse to store the normalized value.

---

## Benefits

This allows:

- O(1) updates
- fast queries
- efficient handling of large inputs

---

## Complexity

| Operation | Complexity |
|----------|------------|
| append | O(log MOD) |
| addAll | O(1) |
| multAll | O(1) |
| getIndex | O(1) |

---

## Kotlin Features Used

- ArrayList
- Long arithmetic
- Binary exponentiation
