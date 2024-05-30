//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    const int MOD = 1e9+7;
    int countWays(string s1, string s2) {
        // code here
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(0, 0, s1, s2, dp);
    }
    int solve(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
        if(j>=s2.size())    return 1;
        if(i>=s1.size())    return 0;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(s1[i]==s2[j]) {
            return dp[i][j] = (solve(i+1, j, s1, s2, dp) + solve(i+1, j+1, s1, s2, dp)) % MOD;
        }
    
        return dp[i][j] = solve(i+1, j, s1, s2, dp) % MOD;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends
