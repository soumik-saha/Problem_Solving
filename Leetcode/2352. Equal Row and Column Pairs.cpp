class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid.size(); c++) {
                bool match = true;
                for(int i=0; i<grid.size(); i++) {
                    if(grid[r][i] != grid[i][c]) {
                        match = false;
                        break;
                    }
                }
                cnt += match? 1 : 0;
            }
        };
        return cnt;
    }
};
