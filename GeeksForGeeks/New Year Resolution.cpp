//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int isPossible(int N, int coins[]) {
        vector<vector<int>> dp(N + 1, vector<int>(2025, -1));
        return solve(0, N, coins, 0, dp);
    }

    bool solve(int i, int n, int arr[], int sum, vector<vector<int>>& dp) {
        if (i >= n) {
            if (sum == 2024 or (sum > 0 and (sum % 20 == 0 or sum % 24 == 0))) {
                return true;
            }
            return false;
        }

        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        return dp[i][sum] = solve(i + 1, n, arr, sum + arr[i], dp) || solve(i + 1, n, arr, sum, dp);
    }
};





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends
