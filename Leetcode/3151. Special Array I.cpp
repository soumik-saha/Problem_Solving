class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        bool expected = nums[0]%2==1;
        for(int i=1; i<n; i++) {
            bool curr = nums[i]%2==1;
            if(curr==expected)  return false;
            expected = curr;
        }
        return true;
    }
};
