class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=1; i<n; i++) {
            if(nums[i-1]==nums[i]) {
                nums[i-1] *= 2;
                nums[i] = 0;
            }
        }
        int i = 0;
        for(int idx=0; idx<n; idx++) {
            if(nums[idx]==0)    continue;
            nums[i++] = nums[idx];
        }
        while(i<n) {
            nums[i++] = 0;
        }

        return nums;
    }
};
