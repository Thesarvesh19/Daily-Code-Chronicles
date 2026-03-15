# Fancy Sequence API – C Implementation

## Problem
Design a data structure that supports the following operations efficiently:

- `append(val)` → append value to sequence
- `addAll(inc)` → add `inc` to all elements 
- `multAll(m)` → multiply all elements by `m`
- `getIndex(idx)` → return value at index `idx`

All results must be returned modulo **1e9 + 7**.

---

## Key Idea

Instead of modifying every element in the sequence, we maintain a **global affine transformation**:

value = stored_value * mul + add

Where:

- `mul` = cumulative multiplication factor
- `add` = cumulative addition factor

When appending a value, we **reverse the current transformation** using a **modular inverse** to store a normalized value.

---

## Time Complexity

| Operation | Complexity |
|----------|------------|
| append | O(log MOD) |
| addAll | O(1) |
| multAll | O(1) |
| getIndex | O(1) |

---

## Space Complexity

O(n)

---

## Concepts Used

- Modular Arithmetic
- Fast Exponentiation
- Modular Inverse
- Lazy Transformation

---

## Modulus
