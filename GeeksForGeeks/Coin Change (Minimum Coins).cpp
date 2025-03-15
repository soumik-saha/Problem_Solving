//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
        sort(coins.rbegin(), coins.rend());
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        int ans = solve(0, coins, sum, dp);
        return ans>=1e9 ? -1 : ans;
    }
    int solve(int i, vector<int>& coins, int sum, vector<vector<int>>& dp) {
        if(sum==0) {
            return 0;
        }
        
        if(sum<0 || i==coins.size()) {
            return 1e9;
        }
        
        if(dp[i][sum]!=-1) {
            return dp[i][sum];
        }
        
        int same = 1e9, diff = 1e9;
        for(int ind=i+1; ind<coins.size(); ind++) {
            diff = min(diff, 1 + solve(ind, coins, sum-coins[ind], dp));
        }
        same = 1 + solve(i, coins, sum-coins[i], dp);
        
        return dp[i][sum] = min(same, diff);
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
