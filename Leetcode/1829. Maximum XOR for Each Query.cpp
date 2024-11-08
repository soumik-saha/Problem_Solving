class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n);
        
        int totalXor = 0;
        for(auto num:nums) {
            totalXor ^= num;
        }

        int maxK = (1<<maximumBit)-1;

        for(int i=n-1; i>=0; i--) {
            ans[n-1-i] = totalXor ^ maxK;
            totalXor ^= nums[i];
        }

        return ans;
    }
};
