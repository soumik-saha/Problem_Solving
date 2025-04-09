class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        priority_queue<int> pq;
        for(auto num:st) {
            pq.push(num);
        }
        int ops = 0;
        while(!pq.empty()) {
            if(pq.top()<k)  return -1;
            if(pq.top()!=k) ops++;
            pq.pop();
        }
        return ops;
    }
};
