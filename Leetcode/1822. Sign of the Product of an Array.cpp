class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = nums.size();
        int mul = 1;
        for(int i=0; i<n; i++) {
            if(mul*nums[i]>0){
                mul = 1; 
            }
            else if(mul*nums[i]<0) {
                mul = -1;
            }
            else {
                mul = 0;
            }
        }
        if(mul>0)
            return 1;
        else if(mul<0)
            return -1;
        else
            return 0;
    }
};
