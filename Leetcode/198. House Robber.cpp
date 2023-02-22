class Solution {
public:
    int rob(vector<int>& nums) {
        int m1=0, m2=0;

        for(int i=0; i<nums.size(); i++){
            if(i%2==0){
                m1 = max(m1+nums[i], m2);
            }
            else{
                m2 = max(m1, m2+nums[i]);
            }
        }
        return max(m1, m2);
    }
};
