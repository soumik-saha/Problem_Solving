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
    bool isEvenOddTree(TreeNode* root) {
        if(!root)   return true;
        
        int lvl = 0;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> v;

            while(sz--) {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);

                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            if(lvl%2==0) {
                if(v.size()==1 && v[0]%2==0)    return false;
                for(int i=1; i<v.size(); i++) {
                    if(v[i-1]%2==0 || v[i]%2==0 || v[i-1]>=v[i]) {
                        return false;
                    }
                }
            }
            else {
                if(v.size()==1 && v[0]%2!=0)    return false;
                for(int i=1; i<v.size(); i++) {
                    if(v[i-1]%2!=0 || v[i]%2!=0 || v[i-1]<=v[i]) {
                        return false;
                    }
                }
            }
            lvl++;
        }
        return true;
    }
};
