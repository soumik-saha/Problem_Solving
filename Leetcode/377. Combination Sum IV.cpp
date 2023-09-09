class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(0, nums, target, dp);
    }
    int solve(int i, vector<int>& nums, int target, vector<int>& dp) {
        if(target==0) {
            return 1;
        }

        if(dp[target]!=-1) {
            return dp[target];
        }

        int result = 0;
        for(int ind=0; ind<nums.size(); ind++) {
            if(target-nums[ind] >= 0) {
                result += solve(ind, nums, target-nums[ind], dp);
            }
        }

        return dp[target] = result;
    }
};
