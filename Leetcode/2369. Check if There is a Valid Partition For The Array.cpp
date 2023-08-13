class Solution {
private:
    bool helper(int i, int n, vector<int>& nums, vector<int>&dp) {
        if(i>=n)
            return true;
        
        if(dp[i]!=-1)
            return dp[i];

        if(i+1<n && nums[i]==nums[i+1]) {
            dp[i] = helper(i+2, n, nums, dp);
            if(dp[i])
                return true;
            
            if(i+2<n && nums[i]==nums[i+2]) {
                dp[i] = helper(i+3, n, nums, dp);
                if(dp[i])
                    return true;
            }
        }

        if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1) {
            dp[i] = helper(i+3, n, nums, dp);
            if(dp[i])
                return true;
        }

        return dp[i] = false;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(0, n, nums, dp);
    }
};
