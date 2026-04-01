# 2751. Robot Collisions

## Problem Summary
We are given:
- Positions of robots
- Their health values
- Their movement directions (L or R)

All robots move at the same speed. When two robots collide:
- The robot with lower health is removed
- The stronger robot loses 1 health and continues
- If both have equal health, both are removed

We need to return the health of surviving robots in the original order.

---

## Approach

### Key Idea
Only robots moving **right (R)** can collide with robots moving **left (L)**.

### Steps
1. Combine robot data:
   - position, health, direction, original index

2. Sort robots by position

3. Use a stack:
   - Push robots moving right
   - For robots moving left, resolve collisions

4. Collision rules:
   - If right < left → right removed, left health -1
   - If right > left → left removed, right health -1
   - If equal → both removed

5. Sort survivors by original index and return their health

---

## Complexity

- Time: O(n log n)
- Space: O(n)

---

## Java Solution
See `solution.java`

## Python Solution
See `solution.py`

---

## Example

Input:
positions = [3,5,2,6]  
healths = [10,10,15,12]  
directions = "RLRL"

Output:
[14]

---
