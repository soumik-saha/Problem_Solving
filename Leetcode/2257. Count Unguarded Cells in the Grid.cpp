class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(int i=0; i<walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = 2;
        }
        for(int i=0; i<guards.size(); i++) {
            grid[guards[i][0]][guards[i][1]] = 1;
        }
        for(int i=0; i<guards.size(); i++) {
            int x = guards[i][0], y = guards[i][1];
            for(int j=x-1; j>=0; j--) {
                if(grid[j][y]==1 || grid[j][y]==2)  break;
                grid[j][y] = -1;
            }
            for(int j=x+1; j<m; j++) {
                if(grid[j][y]==1 || grid[j][y]==2)  break;
                grid[j][y] = -1;
            }
            for(int j=y-1; j>=0; j--) {
                if(grid[x][j]==1 || grid[x][j]==2)  break;
                grid[x][j] = -1;
            }
            for(int j=y+1; j<n; j++) {
                if(grid[x][j]==1 || grid[x][j]==2)  break;
                grid[x][j] = -1;
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans += grid[i][j]==0;
            }
        }
        return ans;
    }
};
