class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> v;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i=0; i<nums.size(); i++) {
            v.push(nums[i]);
            if(v.size() > k) 
                v.pop();
        }
    }
    
    int add(int val) {
        v.push(val);
        if(v.size() > size)
            v.pop();
        return v.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
