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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxDepth = findMaxDepth(root);
        return solve(root, 0, maxDepth);
    }
    TreeNode* solve(TreeNode* node, int depth, int &maxDepth) {
        if(!node)   return node;

        TreeNode* left = solve(node->left, depth+1, maxDepth);
        TreeNode* right = solve(node->right, depth+1, maxDepth);

        if(maxDepth==depth+1) {
            return node;
        }

        if(left && right)   return node;
        return left ? left : right;
    }
    int findMaxDepth(TreeNode* node) {
        if(!node)   return 0;
        return 1+max(findMaxDepth(node->left), findMaxDepth(node->right));
    }
};
