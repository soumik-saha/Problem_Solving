class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i>0 && j>0 && arr[i][j]==1) {
                    arr[i][j] += min({arr[i-1][j], arr[i][j-1], arr[i-1][j-1]});
                }
                ans += arr[i][j];
            }
        }

        return ans;
    }
};
