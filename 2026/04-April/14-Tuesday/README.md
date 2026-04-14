# Minimum Total Distance Between Robots and Factories

## Problem Statement

There are robots and factories located on the X-axis.

You are given:
- An integer array `robot` where `robot[i]` is the position of the ith robot.
- A 2D array `factory` where `factory[j] = [positionj, limitj]`.

Each factory can repair at most `limitj` robots.

### Rules

- All robots are initially broken.
- Each robot can move either left or right.
- When a robot reaches a factory that has not reached its capacity, it gets repaired and stops moving.
- Robots do not collide.
- Distance traveled by a robot is `|x - y|`.

### Objective

Return the minimum total distance traveled by all robots such that all robots are repaired.

---

## Approach

1. Sort the `robot` array.
2. Sort the `factory` array based on positions.
3. Expand each factory into multiple slots according to its capacity.
4. Use dynamic programming to assign robots to factory slots optimally.

---

## Dynamic Programming

Define:

dp[i][j] = minimum cost to repair first i robots using first j factory slots

### Transition

dp[i][j] = min(
    dp[i][j-1],
    dp[i-1][j-1] + abs(robot[i-1] - slots[j-1])
)

---

## Complexity

Time Complexity: O(n * m)  
Space Complexity: O(n * m)

Where:
- n = number of robots
- m = total factory capacity

---

## Solution (Python 3)

```python
class Solution:
    def minimumTotalDistance(self, robot: list[int], factory: list[list[int]]) -> int:
        robot.sort()
        factory.sort()
        
        slots = []
        for pos, limit in factory:
            slots.extend([pos] * limit)
        
        m, n = len(robot), len(slots)
        INF = float('inf')
        
        dp = [[INF] * (n + 1) for _ in range(m + 1)]
        
        for j in range(n + 1):
            dp[0][j] = 0
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = dp[i][j - 1]
                dp[i][j] = min(
                    dp[i][j],
                    dp[i - 1][j - 1] + abs(robot[i - 1] - slots[j - 1])
                )
        
        return dp[m][n]
