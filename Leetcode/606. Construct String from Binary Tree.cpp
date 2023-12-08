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
    stringstream ans;
    string tree2str(TreeNode* root) {
        if(!root)   return "";

        preorder(root);

        return ans.str();
    }
private:
    void preorder(TreeNode* node) {
        if(!node)   return;

        ans << node->val;

        if(node->left or node->right) {
            ans << "(";
            preorder(node->left);
            ans << ")";
        }

        if(node->right) {
            ans << "(";
            preorder(node->right);
            ans << ")";
        }
    }
};
