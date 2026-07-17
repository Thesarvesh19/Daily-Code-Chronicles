# LeetCode 3312 – Sorted GCD Pair Queries

## Problem Overview

Given an integer array `nums`, consider every possible unordered pair `(i, j)` where `i < j`.  
For each pair, compute its **Greatest Common Divisor (GCD)**.

All GCD values are collected into a list and sorted in non-decreasing order.

Each query contains an index representing a position in this sorted list, and the task is to return the GCD value located at that position.

Since the number of possible pairs can reach **O(n²)**, generating every pair explicitly is computationally infeasible for large inputs. Therefore, an optimized mathematical approach is required.

---

# Key Insight

Instead of computing the GCD for every pair individually, determine:

- How many pairs have GCD divisible by a number.
- From those counts, calculate how many pairs have GCD exactly equal to that number.
- Construct cumulative frequencies.
- Answer each query using binary search.

This transforms an impossible quadratic solution into an efficient number-theoretic algorithm.

---

# Algorithm

### Step 1 — Count Frequencies

Count the occurrence of every integer in `nums`.

Example:

```
nums = [2,4,6,8]

Frequency

2 → 1
4 → 1
6 → 1
8 → 1
```

---

### Step 2 — Count Multiples

For every possible divisor `d`:

- Count how many numbers are divisible by `d`.

Example:

```
d = 2

Numbers divisible by 2

2
4
6
8

Count = 4
```

---

### Step 3 — Compute Pair Counts

If there are `k` numbers divisible by `d`, then

```
Pairs = k × (k − 1) / 2
```

This counts every pair whose GCD is **a multiple of d**.

---

### Step 4 — Inclusion–Exclusion

The previous count includes:

- gcd = d
- gcd = 2d
- gcd = 3d
- ...

Subtract larger multiples to isolate pairs having GCD exactly equal to `d`.

Formula

```
Exact[d] = TotalPairs[d]
           − Exact[2d]
           − Exact[3d]
           − ...
```

Process divisors from largest to smallest.

---

### Step 5 — Prefix Sum

After obtaining

```
Exact[1]
Exact[2]
Exact[3]
...
```

Create cumulative counts.

Example

```
GCD   Pairs

1      5
2      3
3      2
4      1

Prefix

1 → 5
2 → 8
3 → 10
4 → 11
```

---

### Step 6 — Binary Search

Each query asks:

> Which GCD owns the k-th pair?

Binary search on prefix sums finds the answer efficiently.

---

# Correctness

The algorithm guarantees correctness because:

- Every pair contributes to all divisors of its GCD.
- Inclusion–exclusion removes overcounting.
- Every pair is counted exactly once.
- Prefix sums preserve sorted ordering.
- Binary search retrieves the required GCD in logarithmic time.

---

# Complexity Analysis

Let

- **N** = size of array
- **M** = maximum value inside nums

### Time Complexity

Frequency Counting

```
O(N)
```

Counting Multiples

```
O(M log M)
```

Inclusion–Exclusion

```
O(M log M)
```

Queries

```
O(Q log M)
```

Overall

```
O(N + M log M + Q log M)
```

---

### Space Complexity

Frequency array

```
O(M)
```

Pair count array

```
O(M)
```

Prefix array

```
O(M)
```

Overall

```
O(M)
```

---

# Example

Input

```
nums = [2,4,6]

queries = [0,1,2]
```

Possible pairs

```
(2,4) → 2

(2,6) → 2

(4,6) → 2
```

Sorted GCDs

```
[2,2,2]
```

Answers

```
Query 0 → 2

Query 1 → 2

Query 2 → 2
```

---

# Data Structures Used

- Frequency Array
- Integer Arrays
- Prefix Sum Array
- Binary Search
- Divisor Enumeration

---

# Mathematical Concepts

- Greatest Common Divisor
- Inclusion–Exclusion Principle
- Combinatorics
- Prefix Sums
- Binary Search
- Number Theory

---


# Summary

- Count occurrences of every value.
- Count numbers divisible by each divisor.
- Compute total divisible pairs.
- Apply inclusion–exclusion to obtain exact GCD frequencies.
- Build prefix sums.
- Use binary search to answer each query efficiently.

This approach combines combinatorial counting, number theory, and efficient searching to solve the problem within competitive programming limits.
