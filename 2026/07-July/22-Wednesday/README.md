# LeetCode 3501 – Maximize Active Sections After Trade II

## Problem Overview

Given a binary string and multiple queries, determine the maximum number of active (`1`) sections that can be obtained after performing the allowed trade operation within each query range.

The challenge is to process a large number of queries efficiently while avoiding repeated computations for overlapping segments.

---

## Approach

The solution preprocesses the binary string into contiguous groups of `0`s and records their positions. Instead of examining every character for each query, the algorithm operates on these compressed groups.

A **Sparse Table** is built over the merge values of adjacent zero groups, enabling fast range maximum queries. During query processing, only the relevant zero groups surrounding the query boundaries are analyzed.

This combination of preprocessing and range-query optimization significantly reduces the overall running time.

---

## Algorithm

1. Count the total number of active (`1`) sections.
2. Split the binary string into contiguous zero groups.
3. Store the starting index and length of every zero group.
4. Build an array representing the merge value of every adjacent pair of zero groups.
5. Construct a Sparse Table for efficient range maximum queries.
6. For every query:

   * Compute the contribution of partial zero groups at both boundaries.
   * Evaluate complete zero-group merges inside the query.
   * Handle boundary edge cases.
   * Return the maximum achievable active sections.

---

## Data Structures Used

* Array
* Group Compression
* Sparse Table (Range Maximum Query)
* Pair / Tuple
* Preprocessing

---

## Complexity Analysis

| Operation                 | Complexity             |
| ------------------------- | ---------------------- |
| Preprocessing             | **O(n)**               |
| Sparse Table Construction | **O(m log m)**         |
| Each Query                | **O(1)**               |
| Overall                   | **O(n + m log m + q)** |

Where:

* **n** = length of the binary string
* **m** = number of zero groups
* **q** = number of queries

---

## Key Features

* Efficient preprocessing of zero segments.
* Constant-time query answering after preprocessing.
* Optimized for large inputs.
* Avoids redundant computations.
* Suitable for competitive programming constraints.

---

## Files

```text
3501/
├── solution.py
├── Solution.java
├── Solution.cpp
└── README.md
```


## Summary

This solution transforms the original binary string into compressed zero-group segments and leverages a Sparse Table to answer maximum merge queries efficiently. By combining preprocessing with constant-time range queries, it scales well for large datasets and satisfies the constraints of the problem.
