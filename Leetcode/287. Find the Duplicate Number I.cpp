class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int cur = abs(nums[i]);
            if(nums[cur]<0) {
                return cur;
            }
            nums[cur] *= -1;
        }
        return -1;
    }
};
