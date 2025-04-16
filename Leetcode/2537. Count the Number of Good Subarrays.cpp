class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long count = 0;
        long long pairCnt = 0;
        unordered_map<int, int> mp;

        for(int left=0, right=0; right<n; right++) {
            pairCnt += mp[nums[right]];
            mp[nums[right]]++;
            
            while(pairCnt>=k) {
                count += n-right;
                mp[nums[left]]--;
                pairCnt -= mp[nums[left]];
                left++;
            }
        }

        return count;
    }
};
