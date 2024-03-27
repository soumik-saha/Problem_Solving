class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)    return 0;
        int ans = 0, n = nums.size();
        int mul = 1;

        for(int left=0, right=0; right<n; right++)  {
            mul *= nums[right];

            while(mul>=k) {
                mul /= nums[left++];
            }

            ans += right-left+1;
        }

        return ans;
    }
};
