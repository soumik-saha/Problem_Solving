class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0, m = grid.size(), n = grid[0].size();
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(grid[i][j]<0)
                    count++;
            }
        }
        return count;
    }
};
