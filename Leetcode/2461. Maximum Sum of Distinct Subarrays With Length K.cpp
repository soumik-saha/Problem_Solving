class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long, long long> mp;
        long long ans = 0, sum = 0;
        int i = 0;

        while(i<k && i<nums.size()) {
            mp[nums[i]]++;
            sum += nums[i];
            i++;
        }

        if(mp.size()==k) {
            ans = sum;
        }
        
        while(i<n) {
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0) {
                mp.erase(nums[i-k]);
            }
            sum += nums[i];
            sum -= nums[i-k];
            if(mp.size()==k) {
                ans = max(ans, sum);
            }
            i++;
        }

        return ans;
    }
};
