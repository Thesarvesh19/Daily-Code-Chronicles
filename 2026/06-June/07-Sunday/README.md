# 2196. Create Binary Tree From Descriptions

## Problem

Given a 2D integer array descriptions where:

- descriptions[i] = [parent, child, isLeft]

Construct and return the binary tree.

## Approach

1. Create all nodes lazily.
2. Maintain a hashmap:
   - value -> TreeNode
3. Maintain a set of all child nodes.
4. Connect parent-child relationships.
5. The node that never appears as a child is the root.

## Algorithm

- Iterate through descriptions.
- Create missing nodes.
- Attach child to parent.
- Store child in set.
- Find parent not present in child set.

## Complexity

### Time

O(n)

### Space

O(n)

## Data Structures Used

- HashMap
- HashSet
- Binary Tree

## Example

Input:

[[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]

Output:

[50,20,80,15,17,19]


Every node except the root appears exactly once as a child.

Therefore:

Root = Node that never appears as child.
