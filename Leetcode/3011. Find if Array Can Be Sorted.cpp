class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> v;
        int i=0; 

        while(i<n) {
            int currBit = __popcount(nums[i]);
            while(i<n && __popcount(nums[i])==currBit) {
                pq.push(nums[i]);
                i++;
            }
            while(!pq.empty()) {
                v.push_back(pq.top());
                pq.pop();
            }
        }

        return is_sorted(v.begin(), v.end());
    }
};
