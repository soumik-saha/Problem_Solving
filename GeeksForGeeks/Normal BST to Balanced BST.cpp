void inorder(Node *root, vector<int>&v){
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    
    Node* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        Node* root = new Node(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }
    
    

    Node* buildBalancedTree(Node* root)
    {
    	vector<int>v;
    	inorder(root,v);
    	return sortedArrayToBST(v,0,v.size()-1);
    	
    }
