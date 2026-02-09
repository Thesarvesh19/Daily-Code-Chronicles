# 1382. Balance a Binary Search Tree

##  Problem Description

Given the root of a Binary Search Tree (BST), the task is to return a **balanced BST**
containing the same node values.
 
A BST is considered **balanced** if for every node, the depth difference between
its left and right subtrees is **at most 1**.

If multiple balanced trees are possible, returning **any one** of them is acceptable.

---

##  Approach

The solution leverages a key property of BSTs:

- **Inorder traversal of a BST produces values in sorted order**

### Steps:
1. Perform an inorder traversal and store all node values in a list.
2. Build a balanced BST from the sorted list by:
   - Choosing the middle element as the root
   - Recursively constructing left and right subtrees

This ensures minimal height and balance at every node.

---

##  Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)` (for storing inorder traversal)

---

##  Language Used

- Java

---




