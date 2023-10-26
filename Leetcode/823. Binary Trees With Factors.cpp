class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        const int MOD = 1e9 + 7;
        int n = arr.size();
        int ans = 0;
        vector<long long> dp(n, 1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(arr[i] % arr[j] == 0) {
                    int x = arr[i]/arr[j];
                    auto it = find(arr.begin(), arr.end(), x);
                    if(it != arr.end()) {
                        int ind = it - arr.begin();
                        dp[i] = (dp[i] + dp[j] * dp[ind]) % MOD;
                    }
                }
            }
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};
