# 2492. Minimum Score of a Path Between Two Cities

## Problem

You are given an undirected weighted graph with `n` cities numbered from `1` to `n` and an array `roads`, where each `roads[i] = [a, b, distance]` represents a road between cities `a` and `b` with distance `distance`.

The **score** of a path is defined as the **minimum distance of any road** along that path.

Return the **minimum possible score** of a path between city `1` and city `n`.

---

## Example

### Input

```text
n = 4
roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
```

### Output

```text
5
```

### Explanation

One valid path is:

```text
1 → 2 → 4
```

The road distances are:

```text
9, 5
```

The score of this path is:

```text
min(9, 5) = 5
```

No other path has a smaller possible score.

---

# Approach

Since the graph is undirected, every city reachable from city `1` belongs to the same connected component.

Instead of checking every possible path from `1` to `n`, we can traverse the connected component containing city `1` using **DFS** or **BFS**.

During traversal:

* Visit every reachable city.
* Track the minimum edge weight encountered.
* The smallest edge weight in the connected component is the answer.

This works because any edge in the connected component can be included in some valid path between city `1` and city `n`.

---

# Algorithm

1. Build an adjacency list.
2. Start DFS/BFS from city `1`.
3. Mark visited cities.
4. For every traversed edge:

   * Update the answer with the minimum edge weight.
5. Return the minimum edge weight found.

---

# Correctness

* Every city that can be part of a path from `1` to `n` is visited.
* Every road in the connected component is examined.
* The minimum edge weight in this component is exactly the minimum score obtainable for a path from `1` to `n`.

Therefore, the algorithm always returns the correct answer.

---

# Complexity Analysis

* **Time Complexity:** `O(n + m)`
* **Space Complexity:** `O(n + m)`

where:

* `n` = number of cities
* `m` = number of roads

---


# Key Concepts

* Graph Traversal
* Breadth-First Search (BFS)
* Depth-First Search (DFS)
* Connected Components
* Adjacency List

---

# Tags

`Graph` `BFS` `DFS` `Union Find` `Shortest Path` `Traversal`
