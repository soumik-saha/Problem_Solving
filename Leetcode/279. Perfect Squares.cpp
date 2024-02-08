class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solve(dp, n);
    }
    int solve(vector<int>& dp, int n) {
        if(n<=3)    return n;
        if(dp[n]!=-1)   return dp[n];
        int ans = INT_MAX;
        for(int i=1; i*i<=n; i++) {
            int req = 1 + solve(dp, n-(i*i));
            ans = min(ans, req);
        }
        return dp[n] = ans;
    }
};
