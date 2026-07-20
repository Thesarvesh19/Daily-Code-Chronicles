# 1260. Shift 2D Grid

## Problem Statement

Given an `m × n` 2D grid and an integer `k`, shift the grid `k` times.

For one shift operation:

- Every element moves one position to the right.
- The last element of each row moves to the first position of the next row.
- The bottom-right element wraps around to the top-left corner.

Return the grid after performing exactly `k` shifts.

---

## Example 1

**Input**

grid = [[1,2,3],[4,5,6],[7,8,9]]

k = 1

**Output**

[[9,1,2],[3,4,5],[6,7,8]]

---

## Example 2

**Input**

grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]

k = 4

**Output**

[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

---

## Approach

Instead of shifting the grid one step at a time, treat the entire matrix as a
single one-dimensional sequence.

For every element:

1. Convert its `(row, column)` position into a linear index.
2. Add `k` to obtain its new position.
3. Use modulo with the total number of cells to wrap around.
4. Convert the new index back into row and column coordinates.
5. Place the value into its new location.

This computes the final position of every element directly.

---

## Algorithm

1. Compute the number of rows and columns.
2. Calculate the total number of cells.
3. Reduce `k` using modulo.
4. Create an empty answer matrix.
5. Traverse every cell.
6. Find its destination index.
7. Convert that index back to `(row, column)`.
8. Store the element.
9. Return the shifted matrix.

---

## Correctness

Each cell has a unique linear index.

Adding `k` and taking modulo maps every original index to exactly one valid
destination index.

Because this mapping is one-to-one, every element is placed exactly once and no
position is overwritten incorrectly.

Therefore, the constructed grid is precisely the grid after `k` shifts.

---

## Complexity Analysis

### Time Complexity

- **O(m × n)**

Each cell is processed once.

### Space Complexity

- **O(m × n)**

