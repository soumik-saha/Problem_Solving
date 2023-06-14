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
    vector<int> nodeValues;

    void dfs(TreeNode* node) {
        if(node==NULL)
            return;
        
        nodeValues.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        sort(nodeValues.begin(), nodeValues.end());

        int minDiff = INT_MAX;

        for(int i=0; i<nodeValues.size()-1; i++) {
            minDiff = min(minDiff, abs(nodeValues[i+1]-nodeValues[i]));
        }

        return minDiff;
    }
};
