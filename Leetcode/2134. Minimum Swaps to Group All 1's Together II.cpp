class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)   return 0;
        int totalOnes = 0;
        for(int num:nums) {
            if(num==1)  totalOnes++;
        }
        if (totalOnes == 0) return 0;
        for(int i=0; i<n; i++) {
            nums.push_back(nums[i]);
        }
        vector<int> prefixSum(2*n, 0);
        prefixSum[0] = nums[0];

        for(int i=1; i<nums.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        int ans = INT_MAX;
        for(int i=totalOnes-1; i<2*n; i++) {
            int oneCnt = prefixSum[i] - (i - totalOnes >= 0 ? prefixSum[i - totalOnes] : 0);
            ans = min(ans, totalOnes - oneCnt);
        }
        return ans;
    }
};
