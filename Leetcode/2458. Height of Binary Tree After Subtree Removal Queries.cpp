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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> resultMap;
        unordered_map<TreeNode*, int> heightMap;

        dfs(root, 0, 0, resultMap, heightMap);

        vector<int> res;
        for(auto q:queries) {
            res.push_back(resultMap[q]);
        }   

        return res;
    }
    void dfs(TreeNode* node, int depth, int maxVal, unordered_map<int, int>& resMap, unordered_map<TreeNode*, int>& heightMap) {
        if(!node) {
            return;
        }

        resMap[node->val] = maxVal;

        dfs(node->left, depth+1, max(maxVal, depth+1+height(node->right, heightMap)), resMap, heightMap);
        dfs(node->right, depth+1, max(maxVal, depth+1+height(node->left, heightMap)), resMap, heightMap);
    }
    int height(TreeNode* node, unordered_map<TreeNode*, int>& heightMap) {
        if(!node)   return -1;

        if(heightMap.find(node)!=heightMap.end()) {
            return heightMap[node];
        }

        return heightMap[node] = 1 + max(height(node->left, heightMap), height(node->right, heightMap));
    }
};
