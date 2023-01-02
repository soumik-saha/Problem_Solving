//User function Template for C++
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

class Solution {
  public:
    vector<int> maximumValue(Node* node) {
        vector<int> ans;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty())
        {
            int n = q.size() , maxm = INT_MIN;
            for(int i=0;i<n;i++)
            {
                Node* parent = q.front() ; q.pop();
                maxm  = max(maxm,parent->data);
                if(parent->left!=NULL) q.push(parent->left);
                if(parent->right!=NULL) q.push(parent->right);
            }
            ans.push_back(maxm);
        }
        return ans;
    }
};
