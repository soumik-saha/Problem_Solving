class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int kInversePairs(int n, int k) {
        if(n==0)    return 0;
        dp = vector<vector<int>>(n+1, vector<int>(k+1, 0));
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=k; j++) {
                if(j==0) {
                    dp[i][j] = 1;
                    continue;
                }
                for(int l=0; l<=min(i-1, j); l++) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-l]) % MOD;
                }
            }
        }
        return dp[n][k];
    }
};
