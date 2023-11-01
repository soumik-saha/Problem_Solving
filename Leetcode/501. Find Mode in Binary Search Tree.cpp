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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> count;
        preorder(root, count);

        int maxi = 0;
        for(auto it : count) {
            maxi = max(maxi, it.second);
        }

        vector<int> ans;
        for(auto it : count) {
            if(it.second==maxi)
                ans.push_back(it.first);
        }

        return ans;
    }
    void preorder(TreeNode* root, unordered_map<int, int>& count) {
        if(!root)   return;

        count[root->val]++;
        preorder(root->left, count);
        preorder(root->right, count);
    }
};
