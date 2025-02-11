bool isBST(Node* root, int minValue = INT_MIN, int maxValue = INT_MAX) {
    // Base case: an empty tree is a valid BST
    if (!root) return true;

    // Check if the current node's value is within the valid range
    if (root->data <= minValue || root->data >= maxValue) {
        return false;
    }

    // Recursively check the left and right subtrees with updated ranges
    return isBST(root->left, minValue, root->data) && isBST(root->right, root->data, maxValue);
}
