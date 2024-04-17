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
    string smallestFromLeaf(TreeNode* root) {
        priority_queue<string, vector<string>, greater<string>> pq;
        string curr;

        dfs(root, pq, curr);

        return pq.top();
    }
    void dfs(TreeNode* root, priority_queue<string,  vector<string>, greater<string>>& pq, string curr) {
        if (!root) {
            return;
        }

        if (!root->left && !root->right) {
            curr += root->val + 'a';
            reverse(curr.begin(), curr.end());
            pq.push(curr);
        }

        curr += root->val + 'a';

        dfs(root->left, pq, curr);
        dfs(root->right, pq, curr);
    }
};
