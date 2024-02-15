class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = -1;
        long long perimeter = 0;
        int cnt = 0;
        long long maxi = 0;
        for(int i=0; i<nums.size(); i++) {
            if(cnt>=3) {
                if(nums[maxi]<perimeter-nums[maxi]) {
                    ans = max(ans, perimeter);
                }
            }
            perimeter += nums[i];
            cnt++;
            if(nums[i]>nums[maxi]) {
                maxi = i;
            }
        }
        if(cnt>=3) {
            if(nums[maxi]<perimeter-nums[maxi]) {
                ans = max(ans, perimeter);
            }
        }
        return ans;
    }
};
