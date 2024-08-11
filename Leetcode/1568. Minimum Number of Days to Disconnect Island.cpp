class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = countIslands(grid);

        if(count!=1)    return 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==0)   continue;

                grid[i][j] = 0;
                int newCount = countIslands(grid);

                if(newCount!=1) return 1;

                grid[i][j] = 1;
            }
        }

        return 2;
    }
    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    dfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        vis[i][j] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        for(int k=0; k<4; k++) {
            int nx = i+dx[k];
            int ny = j+dy[k];

            if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1 && !vis[nx][ny])
                dfs(nx, ny, grid, vis);
        }
    }
};
