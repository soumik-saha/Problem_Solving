class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        priority_queue<int> pq;
        for(int num:nums) {
            pq.push(num);
        }
        while(!pq.empty() && k>0) {
            double val = pq.top();
            pq.pop();
            ans += val;
            k--;
            pq.push(ceil(val/3));
        }
        return ans;
    }
};
