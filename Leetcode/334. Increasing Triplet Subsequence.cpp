class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int q1=INT_MAX, q2=INT_MAX;
        for(auto it : nums){
            if(it<=q1){
                q1=it;
            }
            else if(it<=q2){
                q2=it;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
