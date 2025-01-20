class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, vector<int>> indices;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                indices[mat[i][j]] = {i,j};
            }
        }
        vector<int> countX(m+1, 0), countY(n+1, 0);
        for(int i=0; i<m*n; i++) {
            countX[indices[arr[i]][0]]++;
            countY[indices[arr[i]][1]]++;
            if(countX[indices[arr[i]][0]]==n || countY[indices[arr[i]][1]]==m) {
                return i;
            }
        }
        return -1;
    }
};
