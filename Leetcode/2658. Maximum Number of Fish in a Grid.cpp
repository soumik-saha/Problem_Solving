class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int maxFish = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int currFish = 0;
                if(!vis[i][j] && grid[i][j]>0) {
                    currFish = dfs(i, j, grid, vis);
                }
                maxFish = max(maxFish, currFish);
            }
        }

        return maxFish;
    }

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]==0) {
            return 0;
        }

        vis[i][j] = true;

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int ans = grid[i][j];

        for(int k=0; k<4; k++) {
            int nx = i+dx[k];
            int ny = j+dy[k];

            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && !vis[nx][ny] && grid[nx][ny]>0) {
                ans += dfs(nx, ny, grid, vis);
            }
        }

        return ans;
    }
};
