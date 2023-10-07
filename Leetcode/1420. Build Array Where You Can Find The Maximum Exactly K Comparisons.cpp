class Solution {
public:
    const int MOD = 1e9+7;
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        return dp(0, 0, k, memo, m, n);
    }
    int dp(int i, int maxSoFar, int remain, vector<vector<vector<int>>>& memo, int m, int n) {
        if(i==n) {
            if(remain==0)   return 1;
            return 0;
        }
        if(remain<0)    return 0;

        if(memo[i][maxSoFar][remain] != -1) {
            return memo[i][maxSoFar][remain];
        }

        int ans = 0;
        for(int num=1; num<=maxSoFar; num++) {
            ans = (ans+dp(i+1, maxSoFar, remain, memo, m, n)) % MOD;
        }

        for(int num=maxSoFar+1; num<=m; num++) {
            ans = (ans+dp(i+1, num, remain-1, memo, m, n)) % MOD;
        }

        return memo[i][maxSoFar][remain] = ans;
    }
};
