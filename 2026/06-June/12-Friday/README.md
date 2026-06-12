# 3559. Number of Ways to Assign Edge Weights II

## Problem Statement

You are given an undirected tree with `n` nodes and a list of queries.

For each query `(u, v)`, consider the unique path between nodes `u` and `v`.

Each edge on the path can be assigned a weight of either `1` or `2`.

Return the number of assignments such that the total weight of the path is odd, modulo `10^9 + 7`.

---

## Approach

### Key Observation

A path with `d` edges has `2^d` possible weight assignments.

The path sum is odd when an odd number of edges receive weight `1`.

For any non-empty path:

- Half of all assignments produce an odd sum.
- Half produce an even sum.

Therefore:

```text
Answer = 2^(d - 1)
```

where `d` is the number of edges in the path.

If:

```text
u == v
```

then the path contains no edges, so the answer is:

```text
0
```

---

## Efficient Distance Calculation

To find the distance between two nodes efficiently:

1. Root the tree at node `1`.
2. Precompute ancestors using Binary Lifting.
3. Answer Lowest Common Ancestor (LCA) queries in `O(log N)`.
4. Compute:

```text
distance(u, v)
=
depth[u] + depth[v] - 2 × depth[LCA(u, v)]
```

5. Return:

```text
2^(distance - 1) mod (10^9 + 7)
```

---

## Algorithm

1. Build the tree.
2. Run DFS to compute depths.
3. Build Binary Lifting tables.
4. For each query:
   - Find LCA.
   - Compute path length.
   - If length is `0`, return `0`.
   - Otherwise return `2^(length - 1) mod M`.

---

## Complexity Analysis

### Preprocessing

```text
Time:  O(N log N)
Space: O(N log N)
```

### Per Query

```text
Time:  O(log N)
Space: O(1)
```

### Total

```text
Time:  O((N + Q) log N)
Space: O(N log N)
```

---

## Data Structures Used

- Adjacency List
- Depth Array
- Binary Lifting Table
- Fast Modular Exponentiation

---

## Key Formula

For a path containing `d > 0` edges:

```text
Number of Valid Assignments = 2^(d - 1)
```

because exactly half of all assignments produce an odd path sum.

---

## Tags

Tree, DFS, LCA, Binary Lifting, Math, Modular Arithmetic, Graphs
