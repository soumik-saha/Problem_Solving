class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return true;
        bool ans = true;

        for(int i=0; i<n-1; i++) {
            if(nums[i]>nums[i+1])
                ans = false;
        }

        if(ans) return ans;
        ans = true;

        for(int i=0; i<n-1; i++) {
            if(nums[i]<nums[i+1])
                ans = false;
        }

        return ans;
    }
};
