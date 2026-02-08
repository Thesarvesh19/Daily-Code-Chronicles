# Balanced Binary Tree

This repository contains solutions to determine whether a binary tree
is height-balanced.

A binary tree is considered balanced if, for every node, the height
difference between its left and right subtrees is no more than one.

## Approach

The solution uses a bottom-up recursive strategy:

- Compute the height of left and right subtrees.
- If any subtree is unbalanced, propagate a failure signal.
- Otherwise, return the current node height.

This ensures the solution runs in linear time.

## Implementations

- **Java**: Uses recursion with early termination when imbalance is found.
- **C**: Uses the same logic adapted to a struct-based tree representation.

## Time & Space Complexity

- **Time Complexity**: O(n)
- **Space Complexity**: O(h), where h is the height of the tree
