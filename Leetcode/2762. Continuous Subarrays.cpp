class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long n = nums.size();
        long long ans = 0;
        map<int, int> mp;
        for(int l=0, r=0; r<n; r++) {
            mp[nums[r]]++;
            while(abs(mp.rbegin()->first-mp.begin()->first)>2) {
                mp[nums[l]]--;
                if(mp[nums[l]]==0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans += r-l+1;
        }
        return ans;
    }
};
