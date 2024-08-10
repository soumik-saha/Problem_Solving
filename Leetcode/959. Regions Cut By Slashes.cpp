class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> expandedGrid(n*3, vector<int>(n*3, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int baseRow = i*3;
                int baseCol = j*3;

                if(grid[i][j]=='\\') {
                    expandedGrid[baseRow][baseCol] = 1;
                    expandedGrid[baseRow+1][baseCol+1] = 1;
                    expandedGrid[baseRow+2][baseCol+2] = 1;
                }
                else if(grid[i][j]=='/') {
                    expandedGrid[baseRow][baseCol+2] = 1;
                    expandedGrid[baseRow+1][baseCol+1] = 1;
                    expandedGrid[baseRow+2][baseCol] = 1;
                }
            }
        }

        int ans = 0;

        for(int i=0; i<n*3; i++) {
            for(int j=0; j<n*3; j++) {
                if(expandedGrid[i][j]==0) {
                    floodFill(i, j, expandedGrid);
                    ans++;
                }
            }
        }
        return ans;
    }
    void floodFill(int i, int j, vector<vector<int>>& expGrid) {
        queue<pair<int, int>> q;
        expGrid[i][j] = 1;
        q.push({i, j});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while(!q.empty()) {
            auto [currRow, currCol] = q.front();
            q.pop();
            for(int k=0; k<4; k++) {
                int nx = currRow+dx[k];
                int ny = currCol+dy[k];
                if(nx>=0 && ny>=0 && nx<expGrid.size() && ny<expGrid.size() && expGrid[nx][ny]==0) {
                    expGrid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};
