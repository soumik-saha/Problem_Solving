//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dfs(Node *root, int up_sum)
{
    // if it's null then return 1e8 as a max value
    if (root == nullptr)
        return 1e8;

    // if it's leaf node then return root->data
    if (root->left == nullptr and root->right == nullptr)
        return root->data;

    // find left sum
    int left = dfs(root->left, up_sum);
    // find right sum
    int right = dfs(root->right, up_sum);

    // who is maximum
    if (up_sum - left >= up_sum - right)
        return root->data + left;
    else
        return root->data + right;
}
int maxDifferenceBST(Node *root, int target)
{
    int upSum = 0;
    while (root != nullptr)
    {
        if (root->data == target)
        {
            int left = dfs(root->left, upSum);

            int right = dfs(root->right, upSum);

            if (left == 1e8 and right == 1e8)
                return upSum;

            return max(upSum - left, upSum - right);
        }

        upSum += root->data;

        if (root->data > target)
            root = root->left;
        else
            root = root->right;
    }

    return -1;
}
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends
