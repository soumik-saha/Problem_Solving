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
    int sum=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return sum;
    }
    void dfs(TreeNode* node, int low, int high){
        if(node!=NULL){
            if(node->val>=low && node->val<=high)
                sum+=node->val;
            if(low<node->val)
                dfs(node->left, low, high);
            if(high>node->val)
                dfs(node->right, low, high);
        }
    }
};
