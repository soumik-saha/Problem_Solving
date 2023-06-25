class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(fuel+1, vector<int>(n));

        dp[fuel][start] = 1;
        for(int f=fuel; f>=0; f--) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    int d = abs(locations[i]-locations[j]);
                    if(i!=j && f>=d) {
                        dp[f-d][j] = (dp[f-d][j]+dp[f][i]) % 1000000007;
                    }
                }
            }
        }

        int total = 0;

        for(int i=0; i<=fuel; i++) {
            total = (total + dp[i][finish]) % 1000000007;
        }

        return total;
    }
};
