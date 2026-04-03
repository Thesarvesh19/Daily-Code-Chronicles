# Maximum Walls Destroyed by Robots
 
## Problem Summary

You are given:
- Positions of robots
- Distance each robot can shoot
- Positions of walls

Each robot can shoot either left or right, destroying all walls in range.
However:
- Bullets stop when hitting another robot
- Each robot can shoot only once

Goal: Maximize number of unique walls destroyed.

---

## Approach

### Key Idea

- Sort robots and walls
- Use Dynamic Programming (DP)
- For each robot:
  - Try shooting left
  - Try shooting right
- Use binary search to count walls efficiently

---

## DP State


dp[i][dir]


- `i` = robot index
- `dir` = direction of next robot (0 = left, 1 = right)

---

## Transitions

For each robot:
- Compute valid left range
- Compute valid right range
- Choose maximum

---

## Complexity

- Sorting: O(n log n + m log m)
- DP: O(n log m)

---

## Languages Included

- Python (solution.py)
- Java (solution.java)
- Kotlin (solution.kt)

---

## Key Concepts

- Binary Search
- Dynamic Programming
- Interval Constraints
- Greedy Boundaries
