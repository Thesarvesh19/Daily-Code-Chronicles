# LeetCode 2058 - Find the Minimum and Maximum Number of Nodes Between Critical Points

## Problem

Given the head of a linked list, find the minimum and maximum distance between any two **critical points**.

A node is a critical point if it is either:

- A **local maximum**: `prev.val < curr.val > next.val`
- A **local minimum**: `prev.val > curr.val < next.val`

The first and last nodes cannot be critical points.

Return an array `[minimum distance, maximum distance]`.

If there are fewer than two critical points, return `[-1, -1]`.

---

## Approach

Traverse the linked list while keeping track of three important positions:

- `first` - Position of the first critical point.
- `last` - Position of the most recent critical point.
- `min_dist` - Minimum distance between consecutive critical points.

For every node:

1. Check whether it is a local maximum or local minimum.
2. If it is the first critical point, store its position in `first`.
3. Otherwise:
   - Calculate the distance from the previous critical point.
   - Update `min_dist`.
   - Update `last`.
4. After traversal:
   - If fewer than two critical points exist, return `[-1, -1]`.
   - Minimum distance is `min_dist`.
   - Maximum distance is `last - first`.

---

## Python Solution

```python
class Solution:
    def nodesBetweenCriticalPoints(self, head):
        prev = head
        curr = head.next

        first = -1
        last = -1
        min_dist = float('inf')
        pos = 1

        while curr.next:
            nxt = curr.next

            # Check if current node is a critical point
            if ((curr.val > prev.val and curr.val > nxt.val) or
                (curr.val < prev.val and curr.val < nxt.val)):

                if first == -1:
                    first = pos
                else:
                    min_dist = min(min_dist, pos - last)

                last = pos

            prev = curr
            curr = nxt
            pos += 1

        # Fewer than two critical points
        if first == last:
            return [-1, -1]

        return [min_dist, last - first]
