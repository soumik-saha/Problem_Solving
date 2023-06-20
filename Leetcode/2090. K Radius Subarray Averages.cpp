class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) {
            return nums;
        }

        int n = nums.size();
        vector<int> averages(n, -1);

        if (2 * k + 1 > n) {
            return averages;
        }

        long long sum = 0;
        for (int i = 0; i < (2 * k + 1); ++i) {
            sum += nums[i];
        }
        averages[k] = sum / (2 * k + 1);

        for (int i = (2 * k + 1); i < n; ++i) {
            sum = sum - nums[i - (2 * k + 1)] + nums[i];
            averages[i - k] = sum / (2 * k + 1);
        }

        return averages;
    }
};
