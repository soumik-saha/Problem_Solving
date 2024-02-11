class Solution {
public:
    vector<vector<vector<int>>> dp;
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid[0].size(), m = grid.size();
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(grid, 0, 0, n-1);
    }
    int solve(vector<vector<int>>& grid, int i, int r1j, int r2j) {
        int n = grid[0].size();
        int m = grid.size();
        if(r1j<0 || r2j<0 || r1j>=n || r2j>=n)  return 0;
        if(i==m)  return 0;

        if(dp[i][r1j][r2j]!=-1) return dp[i][r1j][r2j];

        int res = 0;
        res += grid[i][r1j];
        if(r1j != r2j)  res += grid[i][r2j];

        int maxForNextRow = 0;
        for(int x=r1j-1; x<=r1j+1; x++) {
            for(int y=r2j-1; y<=r2j+1; y++) {
                maxForNextRow = max(maxForNextRow, solve(grid, i+1, x, y));
            }
        }
        res += maxForNextRow;

        return dp[i][r1j][r2j] = res;
    } 
};
