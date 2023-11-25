class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1]+nums[i];
        }

        for(int i=0; i<n; i++) {
            int leftSum = prefix[i]-nums[i];
            int rightSum = prefix[n-1]-prefix[i];

            int leftCount = i;
            int rightCount = n-i-1;

            int leftTotal = leftCount * nums[i] - leftSum;
            int rightTotal = rightSum - rightCount * nums[i];

            ans.push_back(leftTotal + rightTotal);
        }

        return ans;
    }
};
