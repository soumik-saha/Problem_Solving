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
    vector<TreeNode*> ans;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());

        root = dfs(root, st);

        if(root)    ans.push_back(root);

        return ans;
    }
    TreeNode* dfs(TreeNode* root, unordered_set<int>& st) {
        if (!root)
            return NULL;

        root->left = dfs(root->left, st);
        root->right = dfs(root->right, st);

        if (st.find(root->val) != st.end()) {
            if (root->left)
                ans.push_back(root->left);
            if (root->right)
                ans.push_back(root->right);

            delete root;
            return NULL;
        }

        return root;
    }
};
