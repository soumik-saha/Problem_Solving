//User function Template for C++

/* Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
    public:
    bool countSingleValued(Node * root, int & count){
        if(root == NULL)
            return true;
        bool left = countSingleValued(root->left, count);
        bool right = countSingleValued(root->right, count);
        // If either left subtree or right subtree is not singleValued, then the current subtree is also not singleValued
        if(!left || !right)
            return false;
        // If it has a left child, it's value should be curr_node value
        if(root->left && root->data != root->left->data)
            return false;
        // If it has a right child, it's value should be curr_node value
        if(root->right && root->data != root->right->data)
            return false;
        count++;
        return true;
    }
    
    int singlevalued(Node *root)
    {
        // All leaf nodes are single Valued subtrees
        int count = 0;
        countSingleValued(root, count);
        return count;
    }
};
