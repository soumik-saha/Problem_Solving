class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]!=0) {
                    int gold = solve(i, j, grid);
                    maxGold = max(maxGold, gold);
                }
            }
        }

        return maxGold;
    }   
    int solve(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]==0) {
            return 0;
        }

        int temp = grid[i][j];
        grid[i][j] = 0;

        int up = solve(i-1, j, grid);
        int down = solve(i+1, j, grid);
        int left = solve(i, j-1, grid);
        int right = solve(i, j+1, grid);

        grid[i][j] = temp;

        return temp + max({up, down, left, right});
    }
};
