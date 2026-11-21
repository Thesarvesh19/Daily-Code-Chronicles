# LeetCode 3331 – Find Subtree Sizes After Changes

## Problem Statement
Given a tree rooted at node `0`, represented by a `parent` array, and a string `s` where `s[i]` represents the character assigned to node `i`, modify the parent of each node according to the nearest ancestor having the same character. After modifying the parent relationships, calculate the size of the subtree rooted at each node.

For every node, its new parent is the closest ancestor (excluding itself) whose character matches its own. If no such ancestor exists, its original parent remains unchanged.

## Approach
- Build the original tree using the `parent` array.
- Traverse the tree using DFS while maintaining the ancestor path.
- For each node, search its ancestors from nearest to farthest to find the closest matching character.
- Update the parent of the node if a matching ancestor is found.
- Construct the modified tree using the updated parent array.
- Perform another DFS to calculate the subtree size of every node.

## Complexity Analysis
- **Time Complexity:** O(n²) in the worst case for the straightforward ancestor search and subtree traversal.
- **Space Complexity:** O(n) for adjacency lists, the ancestor path, and the result array (excluding recursion stack overhead).

## Languages
- Python
- C++

## Topics
Tree, Depth-First Search (DFS), Recursion, Graph Traversal
