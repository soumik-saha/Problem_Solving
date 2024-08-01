//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int editDistance(string str1, string str2) {
        // Code here
        vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
        for(int i=0; i<=str1.size(); i++) {
            dp[i][0] = i;
        }
        for(int j=0; j<=str2.size(); j++) {
            dp[0][j] = j;
        }
        for(int i=1; i<=str1.size(); i++) {
            for(int j=1; j<=str2.size(); j++) {
                // nothing
                if(str1[i-1]==str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    // replace
                    int replace = 1 + dp[i-1][j-1];
                    
                    // add
                    int add = 1 + dp[i][j-1];
                    
                    // delete
                    int remove = 1 + dp[i-1][j];
                    
                    dp[i][j] = min({replace, add, remove});
                }
            }
        }
        return dp[str1.size()][str2.size()];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
