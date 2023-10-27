//User function template for C++

class Solution{
  private:
    // int solve(string &s, string &t, int i, int j, vector<vector<int>>& dp) {
    //     if(i<0 || j<0)
    //         return 0;
            
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
        
    //     if(s[i]==t[j])
    //         return dp[i][j] = 1 + solve(s, t, i-1, j-1, dp);
        
    //     int x = solve(s, t, i-1, j, dp);
    //     int y = solve(s, t, i, j-1, dp);
        
    //     return dp[i][j] = max(x,y);
    // }
  public:
    int minimumNumberOfDeletions(string s) { 
        // code here
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));
        
        for(int i=1; i<=s.size(); i++) {
            for(int j=1; j<=s.size(); j++) {
                if(s[i-1]==t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    continue;
                }
                
                int x = dp[i-1][j];
                int y = dp[i][j-1];
                
                dp[i][j] = max(x, y);
            }
        }
        return s.size() - dp[s.size()][s.size()];
        // return s.size() - solve(s, t, s.size()-1, t.size()-1, dp);
    } 
};
