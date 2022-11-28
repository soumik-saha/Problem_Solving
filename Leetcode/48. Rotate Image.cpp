class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        vector<int> mat;
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                mat.emplace_back(matrix[j][i]);
            }
        }
        int k=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j]=mat[k];
                k++;
            }
        }
    }
};
