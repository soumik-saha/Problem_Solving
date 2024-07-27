//User function template for C++

class Solution{
  public:
    int countMin(string str){
        //complete the function here
        int n = str.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        string temp = str;
        reverse(temp.begin(), temp.end());
        
        return n-lcs(0, 0, str, temp, dp);
    }
    int lcs(int i, int j,  string s1, string s2, vector<vector<int>>& dp) {
        if(i==s1.size() || j==s2.size()) {
            return 0;
        }
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(s1[i]==s2[j]) {
            dp[i][j] = 1 + lcs(i+1, j+1, s1, s2, dp);
        }
        else {
            dp[i][j] = max(lcs(i, j+1, s1, s2, dp), lcs(i+1, j, s1, s2, dp));
        }
        
        return dp[i][j];
    }
};
