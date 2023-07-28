class Solution {
private:
    int solve(vector<int>& nums, int start, int end, vector<vector<int>>& memo) {
        if(start==end) {
            return nums[start];
        }

        if(memo[start][end]!=-1)
            return memo[start][end];

        int left = nums[start] - solve(nums, start+1, end, memo);

        int right = nums[end] - solve(nums, start, end-1, memo);

        return memo[start][end] = max(left, right);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1)); 
        return solve(nums, 0, nums.size()-1, memo) >= 0;
    }
};
