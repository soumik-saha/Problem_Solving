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
    int ans = 0;
    int minimumOperations(TreeNode* root) {
        bfs(root);
        return ans;
    }
    void bfs(TreeNode* root) {
        if(!root)   return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> v;
            while(size--) {
                auto node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
            
            auto temp = v;
            sort(temp.begin(), temp.end());
            vector<int> vis(v.size(), 0);
            int count = 0;

            for(int i=0; i<v.size(); i++) {
                if(vis[i]==1 || v[i]==temp[i])  continue;

                int cycleSize = 0;
                int j = i;
                while(!vis[j]) {
                    vis[j] = 1;
                    j = find(temp.begin(), temp.end(), v[j]) - temp.begin();
                    cycleSize++;
                }
                if(cycleSize>0) {
                    count += cycleSize-1;
                }
            }

            ans += count;
        }
    }
};
