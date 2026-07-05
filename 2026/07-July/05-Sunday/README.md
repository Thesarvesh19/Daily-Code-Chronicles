# 1301. Number of Paths with Max Score

## Problem
Given a square board containing digits, obstacles (`X`), a start (`S`), and an end (`E`), find:

1. The maximum score obtainable from `S` to `E`.
2. The number of different paths that achieve this maximum score.

Return the answer as:

```
[maxScore, numberOfPaths]
```

If no valid path exists, return:

```
[0, 0]
```

---

## Approach

Use Dynamic Programming.

Maintain two DP tables:

- `score[i][j]` → Maximum score from `(i,j)` to `S`
- `ways[i][j]` → Number of optimal paths

Traverse from the destination (`S`) backwards toward (`E`).

For each cell:
- Ignore obstacles.
- Consider:
  - Down
  - Right
  - Diagonal Down-Right
- Select the maximum score among reachable neighbors.
- Sum the number of ways for neighbors with the same maximum score.

---

## Complexity

- **Time:** `O(n²)`
- **Space:** `O(n²)`

---

## Topics

- Dynamic Programming
- Matrix
- Grid Traversal
- Counting Paths
```
