class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int maxEle = *max_element(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            int len = 0;
            while(i<n && nums[i]==maxEle) {
                i++;
                len++;
            }
            ans = max(ans, len);
        }
        
        return ans;
    }
};
