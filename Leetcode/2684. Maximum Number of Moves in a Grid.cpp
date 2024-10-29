class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<m; i++) {
            vector<vector<bool>> vis(m, vector<bool>(n, false));
            ans = max(ans, dfs(i, 0, grid, vis));
        }

        return ans;
    }
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int m = grid.size(), n = grid[0].size();
        
        if(i==m || j==n) {
            return 0;
        }

        vis[i][j] = true;

        int dx[3] = {-1, 0, 1};
        int dy[3] = {1, 1, 1};

        int ans = 0;

        for(int k=0; k<3; k++) {
            int nx = i+dx[k];
            int ny = j+dy[k];

            if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]>grid[i][j] && !vis[nx][ny]) {
                ans = max(ans, 1+dfs(nx, ny, grid, vis));
            }
        }

        return ans;
    }
};
