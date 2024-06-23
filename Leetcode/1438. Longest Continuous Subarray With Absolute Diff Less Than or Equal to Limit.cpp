class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int ans = 0;
        multiset<int> window;

        for(int left=0, right=0; right<n; right++) {
            window.insert(nums[right]);

            while(*window.rbegin()-*window.begin()>limit) {
                window.erase(window.find(nums[left++]));
            }

            ans = max(ans, right-left+1);
        }

        return ans;
    }
};
