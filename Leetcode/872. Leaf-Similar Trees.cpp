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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>arr1,arr2;
        inorder(root1,arr1);
        inorder(root2,arr2);
        if(arr1==arr2)
            return true;
        return false;
    }
    void inorder(TreeNode* root, vector<int>&arr){
        if(root!=NULL){
            inorder(root->left,arr);
            inorder(root->right,arr);
            if(root->left==NULL && root->right==NULL)
                arr.push_back(root->val);
        }
    }

};
