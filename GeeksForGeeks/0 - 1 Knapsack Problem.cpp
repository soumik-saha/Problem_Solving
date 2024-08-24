//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n = wt.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        for(int i=1; i<=n; i++) {
            for(int w=0; w<=W; w++) {
                int take = 0;
                if(wt[i-1]<=w) {
                    take = val[i-1] + dp[i-1][w-wt[i-1]];
                }
                
                int non_take = dp[i-1][w];
                
                dp[i][w] = max(take, non_take);
            }
        }
        return dp[n][W];
    }
    int solve(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
        if(i==wt.size() || W<=0) {
            return 0;
        }
        
        if(dp[i][W]!=-1) {
            return dp[i][W];
        }
        
        int take = 0;
        if(wt[i]<=W) {
            take = val[i] + solve(i+1, W-wt[i], wt, val, dp);
        } 
        
        int non_take = solve(i+1, W, wt, val, dp);
        
        return dp[i][W] = max(take, non_take);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends
