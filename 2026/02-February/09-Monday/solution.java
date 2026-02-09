/*
 * 1382. Balance a Binary Search Tree
 * Medium
 *
 * Given the root of a binary search tree, return a balanced binary search tree
 * with the same node values. If there is more than one answer, return any of them.
 *
 * A binary search tree is balanced if the depth of the two subtrees of every node
 * never differs by more than 1.
 *
 * Constraints:
 * 1 <= Number of nodes <= 10^4
 * 1 <= Node.val <= 10^5
 */

import java.util.*;

class Solution {

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> inorder = new ArrayList<>();
        inorderTraversal(root, inorder);
        return buildBalancedBST(inorder, 0, inorder.size() - 1);
    }

    // Inorder traversal to store BST elements in sorted order
    private void inorderTraversal(TreeNode root, List<Integer> inorder) {
        if (root == null) return;

        inorderTraversal(root.left, inorder);
        inorder.add(root.val);
        inorderTraversal(root.right, inorder);
    }

    // Build a balanced BST from sorted list
    private TreeNode buildBalancedBST(List<Integer> inorder, int left, int right) {
        if (left > right) return null;

        int mid = left + (right - left) / 2;
        TreeNode root = new TreeNode(inorder.get(mid));

        root.left = buildBalancedBST(inorder, left, mid - 1);
        root.right = buildBalancedBST(inorder, mid + 1, right);

        return root;
    }
}
