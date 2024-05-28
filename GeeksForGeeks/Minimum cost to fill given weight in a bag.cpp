class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
        return solve(0, n, w, cost, dp);
    }
  private:
    int solve(int idx, int n, int w, vector<int> &cost, vector<vector<int>>& dp) {
        if(w==0) {
            return 0;
        }
        if(idx==n) {
            return 1e9+1;
        }
        if(dp[idx][w]!=-1) {
            return dp[idx][w];
        }
        int ans = 1e9+1;
        if(cost[idx]!=-1 && w>=idx+1) {
            ans = cost[idx] + min(solve(idx, n, w-idx-1, cost, dp), solve(idx+1, n, w-idx-1, cost, dp));
        }
        
        ans = min(ans, solve(idx+1, n, w, cost, dp));
        return dp[idx][w] = ans;
    }
};
