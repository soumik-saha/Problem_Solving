class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid2[0].size();
        int ans = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] && grid1[i][j]==1 && grid2[i][j]) {
                    bool isSubIsland = true;
                    dfs(i, j, grid1, grid2, isSubIsland, vis);
                    if(isSubIsland) {
                        ans += 1;
                    }
                }
            }
        }

        return ans;
    }
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, bool &flag, vector<vector<int>>& vis) {
        int m = grid1.size(), n = grid2[0].size();
        vis[i][j] = 1;

        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};

        for(int k=0; k<4; k++) {
            int newX = i+dx[k], newY = j+dy[k];
            if(newX>=0 && newY>=0 && newX<m && newY<n && !vis[newX][newY] && grid2[newX][newY]==1) {
                if(grid1[newX][newY]==0)    flag = false;    
                dfs(newX, newY, grid1, grid2, flag, vis);
            }
        }
    }
};
