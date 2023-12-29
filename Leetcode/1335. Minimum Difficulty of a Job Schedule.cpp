class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d>n)
            return -1;

        vector<vector<int>> dp(n+1, vector<int>(d+1, -1));
        return solve(0, d, jobDifficulty, dp);
    }
    int solve(int i, int d, vector<int>& arr, vector<vector<int>>& dp) {
        if(d==1) {
            int maxi = INT_MIN;
            for(int ind=i; ind<arr.size(); ind++) {
                maxi = max(maxi, arr[ind]);
            }
            return maxi;
        }

        if(dp[i][d]!=-1) {
            return dp[i][d];
        }

        int maxi = INT_MIN;
        int ans = INT_MAX;
        for(int ind=i; ind<=arr.size()-d; ind++) {
            maxi = max(maxi, arr[ind]);
            ans = min(ans, maxi + solve(ind+1, d-1, arr, dp));
        }

        return dp[i][d] = ans;
    }
};
