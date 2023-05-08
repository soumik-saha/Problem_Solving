class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int l = mat[0].size();
        int lIndex = 0, rIndex = l-1;
        for(int i=0; i<l; i++) {
            if(lIndex == rIndex) {
                sum += mat[i][lIndex];
            }
            else {
                sum += mat[i][lIndex] + mat[i][rIndex];
            }
            lIndex++;
            rIndex--;
        }

        return sum;
    }
};
