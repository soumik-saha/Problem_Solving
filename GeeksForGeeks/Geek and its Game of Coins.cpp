//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findWinner(int n, int x, int y) {
        // code here
        vector<int> dp(n+1, -1);
        return solve(n, x, y, dp);
    }
    int solve(int n, int x, int y, vector<int>& dp) {
        if(n==0)    return 0;
        if(dp[n]!=-1)   return dp[n];
        
        int ans = 0;
        ans |= (!solve(n-1, x, y, dp));
        if(n-x>=0)
            ans |= (!(solve(n-x, x, y, dp)));
        if(n-y>=0)
            ans |= (!(solve(n-y, x, y, dp)));
            
        return dp[n] = ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends
