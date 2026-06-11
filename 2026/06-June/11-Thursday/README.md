# 3558. Number of Ways to Assign Edge Weights I

## Approach

The tree is rooted at node 1.

Let `d` be the maximum depth of the tree.
 
Each edge can be assigned either:
- 1 (odd)
- 2 (even)

For a path containing `d` edges:

- Total assignments = `2^d`
- Exactly half produce an odd path sum.
- Therefore the number of valid assignments is:

`2^(d-1)`

So:

1. Build the tree.
2. Use BFS from node 1 to find the maximum depth.
3. Return `2^(depth-1) mod (1e9+7)`.

## Complexity

- Time: O(n)
- Space: O(n)
