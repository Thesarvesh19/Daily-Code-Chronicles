# LeetCode 2265 — Count Nodes Equal to Average of Subtree

## Problem

Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

The average is calculated using integer division.

### Example

For a subtree:

```text
    4
   / \
  8   5
```

The average is:

```text
(4 + 8 + 5) / 3 = 17 / 3 = 5
```

Since the average is not equal to the root value `4`, this node is not counted.

---

## Approach

Use **Depth-First Search (DFS)** to process each node.

For every subtree, calculate:

* The **sum** of all node values.
* The **number of nodes** in the subtree.

For the current node:

```text
subtreeSum = leftSum + rightSum + node->val
subtreeCount = leftCount + rightCount + 1
```

Then check:

```text
subtreeSum / subtreeCount == node->val
```

If the condition is true, increment the answer.

The DFS returns the sum and count of the current subtree to its parent.

---

## C++ Solution

```cpp
class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* node) {
        if (!node)
            return {0, 0};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int sum = left.first + right.first + node->val;
        int count = left.second + right.second + 1;

        if (sum / count == node->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

---

## Complexity

* **Time Complexity:** `O(n)`
  Each node is visited exactly once.

* **Space Complexity:** `O(h)`
  Due to the recursive DFS stack, where `h` is the height of the binary tree.

---

## Key Idea

At each node, instead of traversing its entire subtree again, compute the **sum and count once** using postorder DFS and pass them back to the parent.

This makes the solution efficient with a single traversal of the tree.
