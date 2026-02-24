"""
Problem: Sum of Root To Leaf Binary Numbers

You are given the root of a binary tree where each node contains either 0 or 1.
Each root-to-leaf path represents a binary number.

Return the total sum of all root-to-leaf binary numbers.
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumRootToLeaf(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def dfs(node, current):
            if not node:
                return 0
            current = (current << 1) | node.val
            if not node.left and not node.right:
                return current
            return dfs(node.left, current) + dfs(node.right, current)

        return dfs(root, 0)
