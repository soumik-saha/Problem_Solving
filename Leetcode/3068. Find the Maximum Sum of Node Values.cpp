class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0, count = 0, sacrifice = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            if((nums[i]^k)>nums[i]) {
                ans += nums[i]^k;
                count++;
                sacrifice = min(sacrifice, (long long)(nums[i]^k) - (long long)(nums[i]));
            }
            else {
                ans += nums[i];
                sacrifice = min(sacrifice, (long long)(nums[i]) - (long long)(nums[i]^k));
            }
        }

        return (count%2==0) ? ans : ans - sacrifice;
    }
};
