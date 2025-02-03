class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int incLength = 1, decLength = 1, maxLength = 1;

        for(int i=0; i<n-1; i++) {
            if(nums[i+1]>nums[i]) {
                incLength++;
                decLength = 1;
            }
            else if(nums[i+1]<nums[i]) {
                decLength++;
                incLength = 1;
            }
            else {
                incLength = decLength = 1;
            }

            maxLength = max({maxLength, incLength, decLength});
        }

        return maxLength;
    }
};
