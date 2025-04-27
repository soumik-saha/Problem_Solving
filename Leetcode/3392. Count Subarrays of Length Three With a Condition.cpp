class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;

        int sum = 0;
        int count = 0;

        for(int i=0; i<n-2; i++) {
            sum = nums[i] + nums[i+2];
            count += (sum*2==nums[i+1]) ? 1 : 0;
        }

        return count;
    }
};
