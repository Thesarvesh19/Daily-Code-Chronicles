# Walking Robot Simulation II
 
## Problem Overview

We are given a rectangular grid of size `width x height`. A robot starts at position `(0, 0)` facing **East**.

The robot follows commands:
- Move forward `num` steps
- If it hits a boundary, it turns **90° counterclockwise** and continues

We need to implement:
- `step(num)`
- `getPos()`
- `getDir()`

---

## Key Observations

### 1. Robot moves only along the boundary

The robot never enters inner cells. It keeps walking along the edges of the rectangle.

### 2. Movement is cyclic

The robot repeats its path after completing one full loop around the rectangle.

### 3. Perimeter formula

Total steps in one cycle:


cycle = 2 * (width + height) - 4


---

## Approach

### Step 1: Reduce unnecessary movement

Instead of simulating all steps:

num = num % cycle


This avoids large computations.

---

### Step 2: Handle full cycle edge case

If:

num % cycle == 0


and robot has already moved before, then:


num = cycle


This ensures correct direction update.

---

### Step 3: Simulate movement

We track:
- `(x, y)` position
- `dir` direction:
  - 0 → East
  - 1 → North
  - 2 → West
  - 3 → South

At each step:
- Move forward if possible
- Else turn left (counterclockwise)

---

## Direction Order


East → North → West → South → East


---

## Complexity Analysis

### Time Complexity
- `O(cycle)` per step call
- Maximum cycle ≈ 400

### Space Complexity
- `O(1)`

---

## Example


Input:
Robot(6, 3)

Operations:
step(2)
step(2)
getPos() → [4, 0]
getDir() → "East"


---

## Why This Works

- Avoids brute force simulation
- Uses cyclic nature of movement
- Efficient even for large `num`

---

## Summary

- Robot moves only on perimeter
- Use modulo to optimize steps
- Carefully handle direction changes
- Maintain state of position and direction

---

## Tags

- Simulation
- Math
- Implementation
- Design
