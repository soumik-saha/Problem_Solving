class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        solve(0, nums, 0, ans);
        return ans;
    }
    void solve(int i, vector<int>& nums, int xorVal, int &ans) {
        int n = nums.size();
        
        if(i==n) {
            ans += xorVal;
            return;
        }

        // take
        solve(i+1, nums, xorVal^nums[i], ans);
        // not take
        solve(i+1, nums, xorVal, ans);
    }
};
