class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        long long n = nums.size();
        unordered_set<long long> st(nums.begin(), nums.end());
        long long ans = 1;

        for(long long i=0; i<n; i++) {
            long long curr = nums[i];
            long long count = 1;
            while(st.find(curr*curr)!=st.end()) {
                curr *= curr;
                count++;
            }

            ans = max(ans, count);
        }

        return ans == 1 ? -1 : ans;
    }
};
