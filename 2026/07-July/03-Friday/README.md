# 3620. Network Recovery Pathways

## Problem
You are given a directed weighted graph where some nodes are online and others are offline.

Find the maximum possible minimum edge weight along a valid path from node `0` to node `n - 1` such that:

- Every node on the path is online.
- The total path cost does not exceed `k`.

Return the maximum possible score, or `-1` if no valid path exists.

---

## Approach

We use **Binary Search + Dijkstra's Algorithm**.

- Build the graph using only online nodes.
- Binary search the minimum edge weight.
- For each candidate value:
  - Ignore all edges with weight smaller than the candidate.
  - Run Dijkstra's algorithm.
  - If destination is reachable within cost `k`, the candidate is feasible.
- Return the largest feasible value.

---

## Algorithm

1. Build adjacency list.
2. Set binary search range using edge weights.
3. While searching:
   - Compute middle value.
   - Run Dijkstra using only edges with weight ≥ middle.
   - If path cost ≤ k:
     - Increase answer.
   - Otherwise:
     - Decrease answer.
4. Return the final answer.

---

## Complexity Analysis

- **Time Complexity:** `O((V + E) log V × log W)`
- **Space Complexity:** `O(V + E)`

Where:

- `V` = Number of vertices
- `E` = Number of edges
- `W` = Maximum edge weight

---

## Topics

- Graph
- Binary Search
- Dijkstra
- Shortest Path
- Priority Queue
