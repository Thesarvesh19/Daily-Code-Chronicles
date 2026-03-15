# Fancy Sequence API – Java Implementation

## Problem

Create a data structure that supports efficient sequence transformations:

Operations:

- append(val)
- addAll(inc)
- multAll(m)
- getIndex(idx)

Return values modulo **1e9 + 7**.

---

## Strategy

We avoid modifying the entire sequence by maintaining a **global affine transformation**:

value = stored_value * mul + add

Where:

- mul = cumulative multiplication
- add = cumulative addition

When appending, we normalize the value by reversing the current transformation using **modular inverse**.

---

## Advantages

This approach avoids expensive full-array updates.

It ensures operations remain efficient even with **100,000 operations**.

---

## Complexity

| Operation | Time |
|----------|------|
| append | O(log MOD) |
| addAll | O(1) |
| multAll | O(1) |
| getIndex | O(1) |

---

## Java Features Used

- ArrayList
- Modular Arithmetic
- Binary Exponentiation
