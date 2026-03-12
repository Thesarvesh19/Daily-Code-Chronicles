# Max Stability Spanning Tree

## Problem Description

You are given:

- `n` nodes labeled from `0` to `n - 1`
- A list of edges where each edge is represented as:


[u, v, s, m]


Where:

- `u` and `v` → endpoints of the edge
- `s` → strength of the edge 
- `m` → mandatory flag  
  - `1` → mandatory edge
  - `0` → optional edge

You may upgrade **at most `k` optional edges**, doubling their strength.

Your goal is to construct a **spanning tree** such that:

- All **mandatory edges must be included**
- The **minimum edge strength in the spanning tree is maximized**

Return the **maximum possible minimum stability**.

If it is impossible to form a spanning tree, return `-1`.

---

## Approach

The solution combines:

- **Binary Search**
- **Disjoint Set Union (Union-Find)**

### Key Ideas

1. **Mandatory Edge Validation**
   - All mandatory edges must be included.
   - If they form a cycle → impossible.

2. **Binary Search on Stability**
   - Search for the maximum possible minimum stability value.

3. **Feasibility Check**
   - For a candidate stability `x`:
     - Mandatory edges must have strength ≥ `x`
     - Optional edges may be upgraded if `2 * strength ≥ x`

4. **Edge Selection**
   - Use **Union-Find** to construct a spanning tree.
   - Prioritize edges that do not require upgrades.

---

## Complexity

Time Complexity:


O(E log S)


Where:

- `E` = number of edges
- `S` = maximum edge strength range

Space Complexity:


O(N)
