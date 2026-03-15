# Fancy Sequence API – C++ Implementation

## Problem Overview

Implement a sequence that supports the following operations efficiently:

- `append(val)`
- `addAll(inc)`
- `multAll(m)`
- `getIndex(idx)`

The result of `getIndex` should be returned **modulo 1e9 + 7**.

---

## Approach

Instead of updating every element in the array, we maintain two global variables:

- `mul`
- `add`

Every element in the sequence follows the transformation:

value = stored_value * mul + add

When inserting a new value, we reverse the transformation to store the normalized value.

---

## Why This Works

Updating every element for `addAll` or `multAll` would lead to **O(n)** operations per update.

Using lazy transformation allows:

- constant time updates
- fast queries

---

## Complexity

| Operation | Complexity |
|----------|------------|
| append | O(log MOD) |
| addAll | O(1) |
| multAll | O(1) |
| getIndex | O(1) |

---

## Techniques Used

- Modular Arithmetic
- Fast Power (Binary Exponentiation)
- Modular Inverse
- Lazy Propagation
