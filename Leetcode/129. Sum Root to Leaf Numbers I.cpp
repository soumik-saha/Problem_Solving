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
    int sumNumbers(TreeNode* root) {
        vector<int> rootToLeaf;

        dfs(root, rootToLeaf, 0);

        int sum = accumulate(rootToLeaf.begin(), rootToLeaf.end(), 0);

        return sum;
    }
    void dfs(TreeNode* root, vector<int>& rootToLeaf, int curr) {
        if(!root)   return;

        curr = (curr*10) + root->val;
        
        if(!root->left && !root->right) {
            rootToLeaf.push_back(curr);
            return;
        }
        
        dfs(root->left, rootToLeaf, curr);
        dfs(root->right, rootToLeaf, curr);
    }
};
