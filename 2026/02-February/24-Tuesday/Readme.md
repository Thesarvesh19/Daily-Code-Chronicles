# Sum of Root To Leaf Binary Numbers

## Problem Description

You are given the root of a binary tree where each node contains either 0 or 1.

Each root-to-leaf path represents a binary number starting from the most significant bit.

Return the sum of all root-to-leaf binary numbers.

---

## Example

Input:
root = [1,0,1,0,1,0,1]

Output:
22

Explanation:
(100) + (101) + (110) + (111)
= 4 + 5 + 6 + 7
= 22

---

## Approach

We use Depth First Search (DFS).

1. Traverse the tree from root to leaf.
2. At each node:
   - Shift the current number to the left (multiply by 2).
   - Add the node's value.
3. If a leaf node is reached, return the current number.
4. Add results from left and right subtrees.

---

## Time Complexity

O(N)

Each node is visited once.

---

## Space Complexity

O(H)

H is the height of the tree (due to recursion stack).

---

## Key Concept

Binary left shift:
current << 1  is same as current * 2
