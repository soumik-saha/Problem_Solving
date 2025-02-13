class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        long long ans = 0;

        while(pq.size()>1 && pq.top()<k) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();

            long long z =  min(x, y) * 2 + max(x, y);
            pq.push(z);
            ans++;
        }

        return ans;
    }
};
