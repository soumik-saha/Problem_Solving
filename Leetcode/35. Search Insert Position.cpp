class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<=nums[0])
            return 0;
        int i;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=target && nums[i-1]<target){
                return i;
            }
        }
        return i;
    }
};
