class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n, 0);
        rightMax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }
        int left = 0, right = 0;
        int ans = 0;
        while(right<n) {
            while(left<right && nums[left]>rightMax[right]) {
                left++;
            }
            ans = max(ans, right-left);
            right++;
        }
        return ans;
    }
};
