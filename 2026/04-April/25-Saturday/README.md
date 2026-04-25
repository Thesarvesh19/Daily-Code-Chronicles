# Maximize Minimum Manhattan Distance on Square Boundary
 
## Problem Summary

You are given:
- An integer `side` representing a square with corners at:
  `(0,0), (0,side), (side,0), (side,side)`
- A list of `points` lying on the boundary of the square
- An integer `k`

Your task is to select `k` points such that the **minimum Manhattan distance between any two selected points is maximized**.

---

## Key Observations

- All points lie on the **perimeter of the square**
- Manhattan distance must be computed directly (cannot rely on perimeter distance alone)
- `k ≤ 25`, which allows efficient dynamic strategies

---

## Approach

### 1. Order Points Along Boundary

We traverse the square boundary in a fixed order:
- Left edge (bottom → top)
- Top edge (left → right)
- Right edge (top → bottom)
- Bottom edge (right → left)

This gives a linear ordering of points.

---

### 2. Binary Search on Answer

We binary search the maximum possible minimum distance `d`.

- Range: `0 → side`
- For each candidate `d`, check feasibility

---

### 3. Feasibility Check (Deque + DP)

We use a deque to maintain sequences of valid selections.

Each state stores:
- Start point of sequence
- Current end point
- Length of sequence

For each new point:
- Try extending previous valid sequences
- Ensure Manhattan distance ≥ `d`
- Track maximum sequence length

If we can build a sequence of length ≥ `k`, `d` is valid.

---

## Complexity

- Sorting: `O(n log n)`
- Binary search: `O(log side)`
- Each check: `O(n)`

**Total Complexity:**  
`O(n log n + n log side)`

---

## Why This Works

- Converts 2D geometry into **ordered traversal**
- Uses **sliding window + DP optimization**
- Avoids expensive pairwise checking
- Efficient due to small `k`

---

## Key Insight

Even though the points lie on a square boundary,  
**Manhattan distance is not equal to perimeter distance**,  
so we must compute distances explicitly.

---

## Languages Implemented

- Python (optimized deque + DP)
- Java (record + deque based solution)
- C (binary search + greedy variant)

---

Input:
side = 2
points = [[0,0],[1,2],[2,0],[2,2],[2,1]]
k = 4

Output:
1


---

## Summary

| Technique        | Used |
|-----------------|------|
| Binary Search   | Yes  |
| Greedy / DP     | Yes  |
| Geometry        | Yes  |
| Optimization    | Deque |

---

## Final Thought

This problem is a strong mix of:
- Geometry
- Greedy strategy
- Binary search on answer
- Sliding window optimization

A great example of turning a 2D problem into a structured 1D traversal.

## Example
