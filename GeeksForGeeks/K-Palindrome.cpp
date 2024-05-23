//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution {
public:
    int kPalindrome(string str, int n, int k) {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (str[i] == str[j])
                    dp[i][j] = 2 + (len == 2 ? 0 : dp[i + 1][j - 1]);
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        int maxPalindromeSize = dp[0][n - 1];
        return (n - maxPalindromeSize) <= k;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
