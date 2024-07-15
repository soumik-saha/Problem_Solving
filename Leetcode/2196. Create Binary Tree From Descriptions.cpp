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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, TreeNode*> mp;

        for(int i=0; i<n; i++) {
            if(mp.find(descriptions[i][0])!=mp.end()) {
                if(mp.find(descriptions[i][1])!=mp.end()) {
                    if(descriptions[i][2]==1)
                        mp[descriptions[i][0]]->left = mp[descriptions[i][1]]; 
                    else {
                        mp[descriptions[i][0]]->right = mp[descriptions[i][1]]; 
                    }
                }
                else {
                    mp[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
                    if(descriptions[i][2]==1)
                        mp[descriptions[i][0]]->left = mp[descriptions[i][1]]; 
                    else {
                        mp[descriptions[i][0]]->right = mp[descriptions[i][1]]; 
                    }
                }
            }
            else {
                mp[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
                if(mp.find(descriptions[i][1])!=mp.end()) {
                    if(descriptions[i][2]==1)
                        mp[descriptions[i][0]]->left = mp[descriptions[i][1]]; 
                    else {
                        mp[descriptions[i][0]]->right = mp[descriptions[i][1]]; 
                    }
                }
                else {
                    mp[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
                    if(descriptions[i][2]==1)
                        mp[descriptions[i][0]]->left = mp[descriptions[i][1]]; 
                    else {
                        mp[descriptions[i][0]]->right = mp[descriptions[i][1]]; 
                    }
                }
            }
        }

        unordered_set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(descriptions[i][1]);
        }

        TreeNode* root = new TreeNode(-1);
        int rootValue = -1;
        for(auto it:descriptions) {
            if(st.find(it[0])!=st.end()) {
                continue;
            }
            rootValue = it[0];
        }
        root = mp[rootValue];

        return root;
    }
};
