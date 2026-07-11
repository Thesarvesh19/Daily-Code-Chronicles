# 2685. Count the Number of Complete Components

## Problem

You are given an integer `n` representing the number of vertices in an undirected graph labeled from `0` to `n - 1`, and a 2D integer array `edges`, where `edges[i] = [ai, bi]` indicates an undirected edge between vertices `ai` and `bi`.

Return the number of **complete connected components** in the graph.

A connected component is **complete** if every pair of distinct vertices in that component is connected by an edge.

---

## Example 1

**Input**

```text
n = 6
edges = [[0,1],[0,2],[1,2],[3,4]]
```

**Output**

```text
3
```

**Explanation**

- Component `{0,1,2}` is complete.
- Component `{3,4}` is complete.
- Component `{5}` is also complete.

So the answer is **3**.

---

## Example 2

**Input**

```text
n = 6
edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
```

**Output**

```text
1
```

**Explanation**

- `{0,1,2}` is a complete component.
- `{3,4,5}` is **not** complete because the edge `(4,5)` is missing.

Hence, the answer is **1**.

---

# Approach

1. Construct an adjacency list for the graph.
2. Traverse each connected component using **DFS** (or BFS).
3. For every component:
   - Count the number of vertices.
   - Sum the degree of every vertex.
4. Since each edge contributes to the degree of two vertices:

   ```text
   edges = degreeSum / 2
   ```

5. A component with `k` vertices is complete only if it contains exactly:

   ```text
   k × (k − 1) / 2
   ```

   edges.

6. Count every component satisfying this condition.

---

# Algorithm

1. Build the adjacency list.
2. Maintain a visited array.
3. For every unvisited vertex:
   - Perform DFS.
   - Count vertices.
   - Compute the total degree.
4. Convert the degree sum into the actual edge count.
5. Compare it with the required number of edges for a complete graph.
6. Increment the answer if they are equal.
7. Return the final count.

---

# Correctness Proof

For every connected component:

- DFS visits every vertex exactly once.
- The sum of all vertex degrees equals twice the number of edges.
- Therefore,

  ```text
  actualEdges = degreeSum / 2
  ```

- A complete graph with `k` vertices always contains

  ```text
  k × (k − 1) / 2
  ```

  edges.

Thus:

- If the edge count matches this value, the component is complete.
- Otherwise, at least one edge is missing, so the component cannot be complete.

Since every connected component is processed exactly once, the algorithm correctly counts all complete components.

---

# Complexity Analysis

- **Time Complexity:** `O(n + m)`
  - `n` = number of vertices
  - `m` = number of edges

- **Space Complexity:** `O(n + m)`
  - Adjacency list
  - Visited array
  - DFS stack

-
