# Robot Simulation with Obstacles

## Problem

A robot starts at (0, 0) on an infinite 2D plane facing north. It follows a sequence of commands:

* `-2` → turn left 90°
* `-1` → turn right 90°
* `1 to 9` → move forward k steps

Some positions contain obstacles. If the robot tries to move into an obstacle, it stops before reaching it.

### Goal

Return the maximum squared Euclidean distance from the origin reached at any point.

---

## Approach

* Use direction mapping:

  * North → (0,1)
  * East → (1,0)
  * South → (0,-1)
  * West → (-1,0)

* Store obstacles in a set for fast lookup

* Process commands:

  * Turn left/right using modulo
  * Move step-by-step to avoid skipping obstacles

* Track maximum distance:

  ```
  max_dist = x^2 + y^2
  ```

---

## Python Solution

```python
class Solution:
    def robotSim(self, commands, obstacles):
        dirs = [(0,1), (1,0), (0,-1), (-1,0)]
        d = 0
        
        x, y = 0, 0
        max_dist = 0
        
        obstacle_set = set(map(tuple, obstacles))
        
        for cmd in commands:
            if cmd == -2:
                d = (d + 3) % 4
            elif cmd == -1:
                d = (d + 1) % 4
            else:
                dx, dy = dirs[d]
                for _ in range(cmd):
                    if (x + dx, y + dy) in obstacle_set:
                        break
                    x += dx
                    y += dy
                    max_dist = max(max_dist, x*x + y*y)
        
        return max_dist
```

---

## Complexity

* Time: O(N)
* Space: O(M)

Where:

* N = number of commands
* M = number of obstacles

---

## Key Points

* Move step-by-step
* Use set for obstacles
* Track max distance continuously

---

## Summary

This problem is a simulation task where careful handling of movement and obstacle detection is required. Efficient lookup and step-by-step execution ensure correctness.
