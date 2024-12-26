class Solution {
public:
    int totalSum = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(2*totalSum+1, INT_MIN));
        return solve(0, nums, target, 0, dp);
    }
    int solve(int i, vector<int>& nums, int target, int sum, vector<vector<int>>& dp) {
        if(i==nums.size()) {
            if(sum==target)
                return 1;
            return 0;
        }

        if(dp[i][totalSum+sum]!=INT_MIN) {
            return dp[i][totalSum+sum];
        }

        int add = solve(i+1, nums, target, sum+nums[i], dp);
        int sub = solve(i+1, nums, target, sum-nums[i], dp);

        return dp[i][totalSum+sum] = add+sub;
    }
};
