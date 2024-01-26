class Solution {
public:
    const long long MOD = 1e9+7;
    int findPaths(int m, int n, int maxMove, int i, int j) {
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(maxMove + 1, -1)));

        return solve(m, n, maxMove, i, j, dp);
        
        return findPaths(m, n, maxMove-1, i-1, j) + findPaths(m, n, maxMove-1, i, j-1) + findPaths(m, n, maxMove-1, i+1, j) + findPaths(m, n, maxMove-1, i, j+1);
    }
    int solve(long long m, long long n, long long maxMove, long long i, long long j, vector<vector<vector<long long>>>& dp) {
        if(i==m || j==n || i<0 || j<0)  return 1;
        if(maxMove==0)    return 0;
        if(dp[i][j][maxMove]!=-1)   return dp[i][j][maxMove];

        long long path = (solve(m, n, maxMove-1, i-1, j, dp) % MOD + solve(m, n, maxMove-1, i, j-1, dp) % MOD + solve(m, n, maxMove-1, i+1, j, dp) % MOD + solve(m, n, maxMove-1, i, j+1, dp) % MOD) % MOD;

        return dp[i][j][maxMove] = path;
    }
};
