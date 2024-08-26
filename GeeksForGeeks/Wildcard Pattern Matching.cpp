//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        // code here
        if(pattern==str)    return 1;
        
        int n = pattern.size();
        int m = str.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return solve(0, 0, pattern, str, dp);
    }
    int solve(int i, int j, string& pattern, string& str, vector<vector<int>>& dp) {
        int n = pattern.size();
        int m = str.size();
        
        if(i==n && j==m) {
            return 1;
        }
        
        if(j==m) {
            int idx = i;
            while(idx<n && pattern[idx]=='*') {
                idx++;
            } 
            return idx==n;
        }
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(pattern[i]==str[j]) {
            return dp[i][j] = solve(i+1, j+1, pattern, str, dp);
        }
        
        if(pattern[i]=='?') {
            return dp[i][j] = solve(i+1, j+1, pattern, str, dp);
        }
        
        if(pattern[i]=='*') {
            return dp[i][j] = (solve(i+1, j, pattern, str, dp) || solve(i, j+1, pattern, str, dp));
        }
        
        return dp[i][j] = 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends
