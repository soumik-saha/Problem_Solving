class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> computeCost(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++) {
            computeCost[i][0] = computeCost[i-1][0] + s1[i-1];
        }

        for(int i=1; i<=n; i++) {
            computeCost[0][i] = computeCost[0][i-1] + s2[i-1];
        }

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s1[i-1]==s2[j-1])
                    computeCost[i][j] = computeCost[i-1][j-1];
                else {
                    computeCost[i][j] = min(s1[i-1] + computeCost[i-1][j], s2[j-1] + computeCost[i][j-1]);
                }
            }
            computeCost[i][0] = computeCost[i-1][0] + s1[i-1];
        }

        return computeCost[m][n];
    }
};
