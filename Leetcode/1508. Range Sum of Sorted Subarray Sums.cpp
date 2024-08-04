class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=i; j<n; j++) {
                sum += nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());

        long long ans = 0;
        const int MOD = 1e9+7;
        for(int i=left-1; i<right; i++) {
            ans = (ans+v[i])%MOD;
        }

        return ans;
    }
};
