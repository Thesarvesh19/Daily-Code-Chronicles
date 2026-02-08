/**
 * Determine if a binary tree is height-balanced.
 *
 * A binary tree is balanced if the height difference between
 * left and right subtrees of every node is at most 1.
 */
 
class Solution {

    public boolean isBalanced(TreeNode root) {
        return height(root) != -1;
    }

    private int height(TreeNode node) {
        if (node == null) {
            return 0;
        }

        int leftHeight = height(node.left);
        int rightHeight = height(node.right);

        if (leftHeight == -1 || rightHeight == -1 ||
            Math.abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return 1 + Math.max(leftHeight, rightHeight);
    }
}
