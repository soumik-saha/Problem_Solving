class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long n = questions.size();
        vector<long long> dp(n+1, -1);
        return solve(0, questions, dp);
    }
    long long solve(long long i, vector<vector<int>>& questions, vector<long long>& dp) {
        if(i>=questions.size()) {
            return 0;
        }

        if(dp[i]!=-1)   return dp[i];

        long long take = questions[i][0] + solve(i+questions[i][1]+1, questions, dp);
        long long skip =  0 + solve(i+1, questions, dp);

        return dp[i] = max(take, skip);
    }
};
