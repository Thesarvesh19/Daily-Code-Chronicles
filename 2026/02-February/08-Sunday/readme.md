# Balanced Binary Tree

This repository contains implementations to determine whether a binary
tree is height-balanced.

A binary tree is considered balanced if, for every node, the height
difference between its left and right subtrees is no more than one.

---

## Approach

All implementations follow a **bottom-up recursive strategy**:

1. Recursively compute the height of left and right subtrees.
2. If any subtree is already unbalanced, propagate a failure signal.
3. If the height difference exceeds one, mark the tree as unbalanced.
4. Otherwise, return the current subtree height.

This avoids repeated height calculations and guarantees efficiency.

---

## Implementations

- **Java (`Solution.java`)**
  - Uses recursion with `-1` as a sentinel value for imbalance.
- **C (`solution.c`)**
  - Implements the same logic using a `TreeNode` struct.
- **Python (`solution.py`)**
  - Clean recursive implementation with early termination.

---

## Complexity Analysis

- **Time Complexity**: O(n)  
  Each node is visited once.
- **Space Complexity**: O(h)  
  Due to recursion stack, where `h` is the height of the tree.

---



- This solution is optimal compared to top-down approaches.
- Works efficiently even for skewed trees.
