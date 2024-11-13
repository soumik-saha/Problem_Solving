class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=0; i<n; i++) {
            long long low = lowerBound(nums, i+1, n-1, lower-nums[i]);
            long long high = lowerBound(nums, i+1, n-1, upper-nums[i]+1);
            ans += high-low;
        }
        return ans;
    }
    long long lowerBound(vector<int>& nums, int lower, int upper, int ele) {
        while(lower<=upper) {
            int mid = lower+(upper-lower)/2;
            if(nums[mid]>=ele) {
                upper = mid-1;
            }
            else {
                lower = mid+1;
            }
        }
        return lower;
    }
};
