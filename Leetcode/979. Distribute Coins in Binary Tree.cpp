/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftExcess = dfs(root->left);
        int rightExcess = dfs(root->right);

        ans += abs(leftExcess) + abs(rightExcess);

        return root->val + leftExcess + rightExcess - 1;
    }
};
