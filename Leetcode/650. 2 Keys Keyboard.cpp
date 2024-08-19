class Solution {
public:
    int minSteps(int n) {
        if(n==1)    return 0;
        vector<vector<int>> dp(n+1, vector<int>(n/2+1, -1));
        return 1 + solve(n, 1, 1, dp);
    }
    int solve(int n, int curr, int copied, vector<vector<int>>& dp) {
        if(n==curr) {
            return 0;
        }
        if(n<curr) {
            return 1000;
        }

        if(dp[curr][copied]!=-1) {
            return dp[curr][copied];
        }

        int cpy = 2+solve(n, curr*2, curr, dp);
        int paste = 1+solve(n, curr+copied, copied, dp);

        return dp[curr][copied] = min(cpy, paste);
    }
};
