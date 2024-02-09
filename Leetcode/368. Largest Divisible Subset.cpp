class Solution {
public:
    unordered_map<int, vector<int>> dp;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return nums;
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0; i<n; i++) {
            vector<int> subset = solve(i, nums);
            if(ans.size()<subset.size()) {
                ans = subset;
            }
        }
        return ans;
    }
    vector<int> solve(int i, vector<int>& nums) {
        if(dp[i].size()!=0) {
            return dp[i];
        }
        vector<int> to_return;
        for(int k=0; k<i; k++) {
            if(nums[i]%nums[k]==0) {
                vector<int> s = solve(k, nums);
                if(s.size()>to_return.size()) {
                    to_return = s;
                }
            }
        }
        to_return.push_back(nums[i]);
        return dp[i] = to_return;
    }
};
