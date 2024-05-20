class Solution {
public:
    int result = 0;
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        solve(0, nums, 0);

        return result; 
    }
    void solve(int i, vector<int>& nums, int currXor) {
        if(i==nums.size()) {
            result += currXor;
            return;
        }

        currXor ^= nums[i];
        solve(i+1, nums, currXor);
        currXor ^= nums[i];
        solve(i+1, nums, currXor);
    }
};
