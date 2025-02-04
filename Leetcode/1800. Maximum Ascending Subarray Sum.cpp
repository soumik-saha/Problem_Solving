class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int currSum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1]>=nums[i])   currSum = 0;
            currSum += nums[i];
            ans = max(currSum, ans);
        }
        return ans;
    }
};
