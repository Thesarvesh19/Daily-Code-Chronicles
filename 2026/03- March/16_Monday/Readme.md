# Get Biggest Three Rhombus Sums in a Grid

## Problem

You are given an `m x n` integer matrix `grid`.

A **rhombus sum** is the sum of the elements that form the **border of a rhombus shape** in the grid. The rhombus is a square rotated by 45° with each corner centered on a grid cell.

Return the **three largest distinct rhombus sums** in descending order.  
If fewer than three distinct sums exist, return all of them.

---

## Example

### Input

grid = [
[1,2,3],
[4,5,6],
[7,8,9]
]


### Output

[20,9,8]


### Explanation

Largest rhombus:


2
4 6
8


Sum = `2 + 4 + 6 + 8 = 20`

---

## Approach

1. **Area 0 Rhombus**
   - Each individual cell is a rhombus.
   - Add all grid values to a set.

2. **Enumerate Centers**
   - Treat each cell as the center of a rhombus.

3. **Expand Rhombus Size**
   - Increase side length `k` while the rhombus stays within the grid.

4. **Traverse the Border**
   - Walk along the four diagonal edges:
     - top → right
     - right → bottom
     - bottom → left
     - left → top

5. **Store Distinct Sums**
   - Use a set to avoid duplicates.

6. **Return Top 3**
   - Sort in descending order and return the first three values.

---

## Complexity

- **Time Complexity:**  
  `O(m * n * min(m, n))`

- **Space Complexity:**  
  `O(k)` for storing rhombus sums.

---

## Key Idea

Rhombus borders follow diagonal directions:


top → right (x+1, y+1)
right → bottom (x+1, y-1)
bottom → left (x-1, y-1)
left → top (x-1, y+1)
