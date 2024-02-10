class Solution {
public:
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k, 0)));
        
        return solve(0, 0, n, k, arr, dp);
    }
    int solve(int i, int j, int n, int k, vector<vector<int>>& arr, vector<vector<vector<int>>>& dp) {
        if(i==n-1 && j==n-1)
            return arr[i][j] == k;
            
        if(i>=n || j>=n || i<0 || j<0 || k<0)
            return 0;
        
        return dp[i][j][k] = solve(i+1, j, n, k-arr[i][j], arr, dp) + solve(i, j+1, n, k-arr[i][j], arr, dp);
    }
};
