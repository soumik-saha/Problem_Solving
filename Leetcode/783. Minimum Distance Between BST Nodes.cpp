class Solution {
public:
    int minDistance = INT_MAX;
    TreeNode* prevValue;
        
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        inorderTraversal(root->left);

        if (prevValue != NULL) {
            minDistance = min(minDistance, root->val - prevValue->val);
        }
        prevValue = root;
        
        inorderTraversal(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);
        
        return minDistance;
    }
};
