# 3161. Block Placement Queries

## Problem Statement

You are given a sequence of queries on an infinite number line.

There are two types of queries:

1. **[1, x]**
   - Place an obstacle at position `x`.

2. **[2, x, sz]**
   - Determine whether a block of size `sz` can be placed entirely within the range `[0, x]` without intersecting any obstacle.

Return a boolean array containing the answer for every type-2 query.

LeetCode Problem:
https://leetcode.com/problems/block-placement-queries/

---

## Approach

The main challenge is efficiently maintaining obstacle positions and determining whether a continuous segment of sufficient length exists before a given position.

### Data Structures Used

### TreeSet

A `TreeSet` is used to maintain all obstacle positions in sorted order.

Operations:

- Find the nearest obstacle on the left.
- Find the nearest obstacle on the right.
- Insert new obstacles efficiently.

Time Complexity:

- Insertion: `O(log n)`
- Search: `O(log n)`

### Segment Tree

A Segment Tree stores the maximum available gap ending at each obstacle.

This allows us to quickly determine:

- The largest obstacle-free segment before a given position.
- Whether a block of required size can fit.

Operations:

- Point Update: `O(log n)`
- Range Maximum Query: `O(log n)`

---

## Key Observation

Suppose we insert an obstacle at position `x`.

Let:

- `left` = nearest obstacle before `x`
- `right` = nearest obstacle after `x`

Before insertion:

```

left ---------------- right

```

Gap:

```

right - left

```

After inserting obstacle:

```

left -------- x -------- right

```

The original gap splits into:

```

x - left
right - x

```

These new gaps are updated inside the Segment Tree.

---

## Algorithm

For each query:

### Type 1 Query

```

[1, x]

```

1. Find nearest obstacle on left.
2. Find nearest obstacle on right.
3. Insert obstacle.
4. Update Segment Tree with new gap lengths.

### Type 2 Query

```

[2, x, sz]

```

1. Find nearest obstacle before `x`.
2. Query Segment Tree for maximum gap before that obstacle.
3. Check if:
   - Any previous gap ≥ `sz`, OR
   - Current trailing segment `(x - previousObstacle)` ≥ `sz`
4. Return result.

---

## Example

### Input

```text
queries = [[1,2],[2,3,2],[2,3,1]]
```

### Execution

#### Query 1

```text
Place obstacle at 2
```

Obstacles:

```text
0 ---- 2
```

#### Query 2

```text
Check block size 2 within [0,3]
```

Available segments:

```text
[0,2] length = 2
[2,3] length = 1
```

Answer:

```text
true
```

#### Query 3

```text
Check block size 1 within [0,3]
```

Answer:

```text
true
```

### Output

```text
[true, true]
```

---

## Correctness

The algorithm maintains all obstacle positions in sorted order.

For every obstacle insertion:

- The affected interval is split correctly.
- Segment Tree stores the updated maximum gap lengths.

For every query:

- All previously available intervals are represented in the Segment Tree.
- The final partial interval ending at `x` is checked separately.

Therefore, every query is answered correctly.

---

## Complexity Analysis

Let:

- `n` = number of queries

### Time Complexity

#### Type 1 Query

```text
O(log n)
```

#### Type 2 Query

```text
O(log n)
```

#### Overall

```text
O(n log n)
```

---

### Space Complexity

#### TreeSet

```text
O(n)
```

#### Segment Tree

```text
O(n)
```

#### Total

```text
O(n)
```

---

## Concepts Used

- TreeSet
- Segment Tree
- Range Maximum Query
- Ordered Set
- Binary Search
- Interval Management
- Data Structures
- Query Processing

---

## Java Solution

```java
// Accepted Java solution code here
```

---

