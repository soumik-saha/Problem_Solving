class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0)    return false;
        int target = sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(0, nums, target, dp);
    }
    bool solve(int i, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if(target==0)   return true;
        if(i>=nums.size() || target<0)  return false;
        if(dp[i][target]!=-1)    return dp[i][target];

        return dp[i][target] = (solve(i+1, nums, target-nums[i], dp) || solve(i+1, nums, target, dp));
    }
};
