class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowOne, colOne, rowZero, colZero;
        for(int i=0; i<m; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) {
                    count++;
                }
            }
            rowOne.push_back(count);
        }
        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<m; j++) {
                if(grid[j][i]==1) {
                    count++;
                }
            }
            colOne.push_back(count);
        }
        for(int i=0; i<m; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(grid[i][j]==0) {
                    count++;
                }
            }
            rowZero.push_back(count);
        }
        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<m; j++) {
                if(grid[j][i]==0) {
                    count++;
                }
            }
            colZero.push_back(count);
        }
        vector<vector<int>> diff(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                diff[i][j] = rowOne[i] + colOne[j] - rowZero[i] - colZero[j];
            }
        }
        return diff;
    }
};
