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
    TreeNode* reverseOddLevels(TreeNode* root) {
        bfs(root);
        return root;
    }
    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag =  false;
        while(!q.empty()) {
            int size = q.size();
            vector<int> ele;
            vector<TreeNode*> nodes;
            while(size--) {
                auto node = q.front();
                q.pop();
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
                ele.push_back(node->val);
                nodes.push_back(node);
            }
            if(flag) {
                reverse(ele.begin(), ele.end());
            }
            int i = 0;
            for(auto& node:nodes) {
                node->val = ele[i++];
            }

            flag = !flag;
        }
    }
};
