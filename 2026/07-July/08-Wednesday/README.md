# 3756. Concatenate Non-Zero Digits and Multiply by Sum II

## Problem

You are given:

- A numeric string `s`.
- A list of queries `[l, r]`.

For every query:

1. Consider the substring `s[l...r]`.
2. Remove every `'0'`.
3. Concatenate the remaining digits to form an integer.
4. Compute the sum of those remaining digits.
5. Return:

```
(concatenated_number × digit_sum) mod (10^9 + 7)
```

Return the answer for every query.

---

## Approach

Instead of processing every query independently, preprocess the string once.

### Preprocessing

- Store every non-zero digit.
- Store its original position.
- Build:
  - Prefix digit sums
  - Prefix concatenated values (mod `1e9+7`)
  - Powers of 10
  - First non-zero index for every position
  - Last non-zero index for every position

Using these arrays, each query can be answered in **O(1)**.

---

## Algorithm

1. Extract all non-zero digits.
2. Record their original indices.
3. Compute:
   - Prefix sums
   - Prefix concatenation values
   - Powers of 10 modulo `1e9+7`
4. Build helper arrays:
   - `first[]`
   - `last[]`
5. For every query:
   - Find first and last non-zero digit.
   - If none exist, answer `0`.
   - Recover the concatenated number using prefix values.
   - Compute digit sum.
   - Return

```
(number × digitSum) % MOD
```

---

## Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Preprocessing | O(n) |
| Each Query | O(1) |
| Total | O(n + q) |
| Extra Space | O(n) |

---

## Correctness

The preprocessing stores enough information to reconstruct:

- every non-zero digit sequence,
- its concatenated value,
- and its digit sum.

Each query only performs constant-time arithmetic using prefix arrays, guaranteeing the same result as constructing the number directly.

---

## Implementations

- ✅ Python
- ✅ Java
- ✅ C++
- ✅ JavaScript

---

## Key Concepts

- Prefix Sum
- Prefix Concatenation
- Modular Arithmetic
- Preprocessing
- Range Queries
- Simulation

---

## Time Complexity

- **Preprocessing:** `O(n)`
- **Per Query:** `O(1)`
- **Overall:** `O(n + q)`

## Space Complexity

- **O(n)**

---

