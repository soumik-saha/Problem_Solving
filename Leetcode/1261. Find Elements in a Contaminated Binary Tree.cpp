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
class FindElements {
public:
    unordered_set<int> nodeSet;

    FindElements(TreeNode* root) {
        root->val = 0;
        fixTree(root, NULL);
    }

    void fixTree(TreeNode* root, TreeNode* parent) {
        if(!root)   return;

        if(parent && parent->left && root==parent->left) {
            root->val = 2*parent->val+1;
        }
        if(parent && parent->right && root==parent->right) {
            root->val = 2*parent->val+2;
        }
        nodeSet.insert(root->val);
        fixTree(root->left, root);
        fixTree(root->right, root);
    }
    
    bool find(int target) {
        return nodeSet.find(target)!=nodeSet.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
