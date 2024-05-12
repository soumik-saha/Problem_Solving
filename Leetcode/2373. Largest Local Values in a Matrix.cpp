class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n-2, vector<int>(n-2, INT_MIN));

        for(int i=0; i<n-2; i++) {
            for(int j=0; j<n-2; j++) {
                for(int k=i; k<=i+2; k++) {
                    for(int l=j; l<=j+2; l++) {
                        result[i][j] = max(result[i][j], grid[k][l]);
                    }
                }
            }
        }

        return result;
    }
};
