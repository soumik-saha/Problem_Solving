class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int minEleInRow = INT_MAX;
                int maxEleInCol = INT_MIN;
                for (int k = 0; k < n; k++) {
                    minEleInRow = min(minEleInRow, matrix[i][k]);
                }

                for (int k = 0; k < m; k++) {
                    maxEleInCol = max(maxEleInCol, matrix[k][j]);
                }

                if (maxEleInCol == minEleInRow) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};
