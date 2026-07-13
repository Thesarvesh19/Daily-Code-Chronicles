# 1391. Check if There is a Valid Path in a Grid

## Problem Statement

You are given an `m × n` grid where each cell represents a street type from **1 to 6**. Every street connects to specific neighboring cells depending on its type.

Determine whether there exists a **valid path** from the **top-left cell (0, 0)** to the **bottom-right cell (m − 1, n − 1)** by following only compatible street connections.

**LeetCode Link:** https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

---

## Example 1

**Input**

```text
grid = [[2,4,3],[6,5,2]]
```

**Output**

```text
true
```

**Explanation**

A continuous street connects the start cell to the destination.

---

## Example 2

**Input**

```text
grid = [[1,2,1],[1,2,1]]
```

**Output**

```text
false
```

---

## Approach

The solution performs a **Breadth-First Search (BFS)** starting from the top-left cell.

For every visited cell:

- Identify the directions allowed by its street type.
- Move only to valid neighboring cells.
- Verify that the neighboring street also connects back to the current cell.
- Continue exploring until the destination is reached.

If the bottom-right cell is visited, return **true**; otherwise return **false**.

---

## Street Connections

| Street Type | Connected Directions |
|-------------|----------------------|
| 1 | Left, Right |
| 2 | Up, Down |
| 3 | Left, Down |
| 4 | Right, Down |
| 5 | Left, Up |
| 6 | Right, Up |

---

## Algorithm

1. Store valid movement directions for each street type.
2. Store the opposite direction for every movement.
3. Start BFS from `(0,0)`.
4. For every neighboring cell:
   - Check grid boundaries.
   - Skip already visited cells.
   - Verify that both streets are compatible.
5. Add valid neighbors to the queue.
6. Return **true** when destination is reached.
7. Otherwise return **false**.

---

## Complexity Analysis

### Time Complexity

```text
O(m × n)
```

Each cell is processed at most once.

### Space Complexity

```text
O(m × n)
```

Required for the visited array and BFS queue.

---

