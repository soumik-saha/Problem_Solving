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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int diameter = 0;
        solve(root, diameter);
        return diameter;
    }
    int solve(TreeNode* node, int& diameter) {
        if(!node)   return 0;

        int left = solve(node->left, diameter);
        int right = solve(node->right, diameter);

        diameter = max(diameter, left+right);

        return 1+max(left, right);
    }
};
