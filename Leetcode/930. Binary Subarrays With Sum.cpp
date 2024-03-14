class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp;

        for(int num:nums) {
            sum += num;
            if(sum == goal) {
                ans++;
            }
            if(mp.find(sum-goal)!=mp.end()) {
                ans += mp[sum-goal];
            }
            mp[sum]++;
        }
        return ans;
    }
};
