# 3534. Path Existence Queries in a Graph II

## Problem Overview

You are given a graph where the connectivity between nodes depends on a distance constraint. For each query, determine the minimum number of moves required to travel from one node to another while satisfying the graph's edge conditions. If no valid path exists, return **-1**.

---

## Intuition

A direct graph traversal for every query would be too slow when the number of queries is large. Instead, we preprocess the graph so that each query can be answered efficiently.

The main idea is:

* Sort the nodes based on their values.
* Compute the farthest reachable position for every node using a sliding window (two-pointer technique).
* Build a **Binary Lifting (Jump Table)** structure that allows jumping multiple steps in logarithmic time.
* For every query, repeatedly perform the largest possible jump until the destination becomes reachable.

This preprocessing significantly reduces the overall running time.

---

## Approach

1. Sort all node values while preserving their original indices.
2. Map every original index to its position in the sorted array.
3. Using a two-pointer technique, determine the farthest reachable node for every position.
4. Construct a Binary Lifting table where:

   * `jump[i][k]` stores the position reached after `2^k` jumps.
5. For each query:

   * Convert both endpoints into sorted positions.
   * Ensure the left position comes before the right position.
   * Use Binary Lifting to make the largest valid jumps.
   * Count the number of jumps required.
   * If the destination cannot be reached, return **-1**.

---

## Algorithm

```
Sort nodes

Map original indices to sorted positions

Compute farthest reachable position
using sliding window

Build Binary Lifting table

For each query:
    Convert indices
    Swap if necessary
    Perform logarithmic jumps
    Return answer
```

---

## Complexity Analysis

### Time Complexity

* Sorting: **O(n log n)**
* Sliding Window Preprocessing: **O(n)**
* Binary Lifting Construction: **O(n log n)**
* Each Query: **O(log n)**

Overall:

**O((n + q) log n)**

where:

* `n` = number of nodes
* `q` = number of queries

---

### Space Complexity

Binary Lifting table requires:

**O(n log n)**

additional memory.

---

## Data Structures Used

* Arrays
* Sorting
* Two Pointers
* Binary Lifting (Sparse Table)
* Index Mapping

---

## Key Concepts

* Binary Lifting
* Greedy Jumping
* Sliding Window
* Offline Preprocessing
* Fast Query Processing

---

## Edge Cases Considered

* Source equals destination
* Unreachable destination
* Duplicate node values
* Queries in reverse order
* Minimum input size
* Maximum constraints

---

