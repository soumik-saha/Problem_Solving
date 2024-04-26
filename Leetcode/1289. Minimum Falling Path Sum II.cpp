class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n = grid.size();
        map<pair<int, int>, int> memo;

        for(int col=0; col<n; col++) {
            ans = min(ans, solve(0, col, grid, memo));
        }

        return ans;
    }
    int solve(int row, int col, vector<vector<int>>& grid, map<pair<int, int>, int>& memo) {
        if(row==grid.size()-1) {
            return grid[row][col];
        }

        int nextMinimum = INT_MAX;
        for(int i=0; i<grid.size(); i++) {
            if(i!=col) {
                nextMinimum = min(nextMinimum, solve(row+1, i, grid, memo));
            }
        }

        memo[{row, col}] = grid[row][col] + nextMinimum;
        return memo[{row, col}];
    }
};
