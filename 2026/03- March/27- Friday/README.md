# 2946. Matrix Similarity After Cyclic Shifts

## Problem
Given a matrix, perform cyclic shifts on rows:
- Even rows → shift left
- Odd rows → shift right

Repeat this process k times.

Return true if the matrix becomes same as original.

---

## Approach

Instead of performing k operations, we reduce it:

effective shift = k % number_of_columns

If shift is 0, matrix remains unchanged.

Otherwise:
- For even rows → left shift
- For odd rows → right shift

For each row:
- Compute the expected shifted position using modular arithmetic
- Compare it directly with the original row

---

## Complexity

Time: O(m * n)  
Space: O(1)

---

## Key Insight

If k % n == 0 → matrix always remains same

We do not simulate k operations.
We directly check final positions using modulo logic.

---

## Implementations

This repository contains solutions in multiple languages:

- Python (`solution.py`)
- Java (`solution.java`)
- Kotlin (`solution.kt`)
- C (`solution.c`)
- C++ (`solution.cpp`)
- JavaScript (`solution.js`)

All implementations follow the same optimized approach.
