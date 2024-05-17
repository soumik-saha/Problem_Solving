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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root, NULL, target);
    }
    TreeNode* solve(TreeNode* node, TreeNode* parent, int target) {
        if(!node)   return NULL;

        TreeNode* left = solve(node->left, node, target);
        TreeNode* right = solve(node->right, node, target);

        if(!left && !right && node->val == target) {
            if(parent) {
                if(parent->left==node) {
                    parent->left = NULL;
                }
                else {
                    parent->right = NULL;
                }
            }
            else {
                node = NULL;
            }
            return NULL;
        }

        return node;
    }
};
