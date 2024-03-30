class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp, mp2;

        for(int left=0, right=0, until=0; right<n; right++) {
            mp[nums[right]]++;
            mp2[nums[right]]++;

            while(mp.size()>k) {
                if(mp[nums[left]]>0) {
                    mp[nums[left]]--;
                    if(mp[nums[left]]==0) {
                        mp.erase(nums[left]);
                    }
                }
                left++;
            }

            while(mp2.size()>=k) {
                if(mp2[nums[until]]>0) {
                    mp2[nums[until]]--;
                    if(mp2[nums[until]]==0) {
                        mp2.erase(nums[until]);
                    }
                } 
                until++;
            }

            if(mp.size()==k)
                ans += until-left;
        }

        return ans;
    }
};
