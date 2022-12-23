class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0, cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=1){
                cnt = 0;
            }
            else{
                cnt++;
            }
            result = max(result, cnt);
        }
        return result;
    }
};
