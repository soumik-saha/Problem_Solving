class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1;

        for(int l=0, r=0; r<n; r++) {
            while(l<r && nums[l]<nums[r]-(2*k)) {
                l++;
            }
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
