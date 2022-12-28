//User function Template for C++

class Solution {
  public:
    // Function to find largest subtree sum.
    int post_order_traversal(Node * root, int * maxSum){
        if(root == NULL)
            return 0;
        int left_value = post_order_traversal(root->left, maxSum);
        int right_value = post_order_traversal(root->right, maxSum);
        int currSum = root->data + left_value + right_value;
        if(currSum > *maxSum)
            *maxSum = currSum;
        return currSum;
    }
    int findLargestSubtreeSum(Node* root)
    {
        int maxSum = INT_MIN;
        post_order_traversal(root, &maxSum);
        return maxSum;
    }
};
