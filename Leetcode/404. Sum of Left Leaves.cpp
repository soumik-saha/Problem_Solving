/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root);
        return ans;
    }
    void solve(TreeNode* root) {
        if(!root)   return;

        if(root->left && !root->left->left && !root->left->right) {
            ans+=root->left->val;
        }

        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
    }
};
