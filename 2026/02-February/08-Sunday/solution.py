"""
Determine if a binary tree is height-balanced.

A binary tree is balanced if the height difference between
left and right subtrees of every node is at most 1.
"""

class Solution:
    def isBalanced(self, root):
        return self._height(root) != -1

    def _height(self, node):
        if not node:
            return 0

        left_height = self._height(node.left)
        right_height = self._height(node.right)

        if left_height == -1 or right_height == -1 or abs(left_height - right_height) > 1:
            return -1

        return 1 + max(left_height, right_height)
