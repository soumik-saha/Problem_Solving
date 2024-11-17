class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        long long cumSum = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> prefSumHeap;

        for(int i=0; i<n; i++) {
            cumSum += nums[i];

            if(cumSum>=k) {
                ans = min(ans, i+1);
            }

            while(!prefSumHeap.empty() && cumSum-prefSumHeap.top().first>=k) {
                ans = min(ans, i-prefSumHeap.top().second);
                prefSumHeap.pop();
            }

            prefSumHeap.emplace(cumSum, i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
