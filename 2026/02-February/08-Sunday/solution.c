/*
 * Determine if a binary tree is height-balanced.
 *
 * A binary tree is balanced if the height difference between
 * left and right subtrees of every node is at most 1.
 */
 
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight == -1 || rightHeight == -1 ||
        abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(struct TreeNode* root) {
    return height(root) != -1;
}
