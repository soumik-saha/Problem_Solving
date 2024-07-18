//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int maxLength = 0;
        int n = arr.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int>(2, -1)));
        
        maxLength = max(solve(0, -1, true, arr, dp), solve(0, -1, false, arr, dp));
        
        return maxLength;
    }
    int solve(int i, int prev, bool inc, vector<int>& arr, vector<vector<vector<int>>>& dp) {
        if(i==arr.size()) {
            return 0;
        }
        
        if(dp[i][prev+1][inc]!=-1) {
            return dp[i][prev+1][inc];
        }
        
        int take = 0;
        if(prev==-1 || (!inc && arr[prev]>arr[i]) || (inc && arr[prev]<arr[i])) {
            take = 1 + solve(i+1, i, !inc, arr, dp);
        }
        
        int nonTake = solve(i+1, prev, inc, arr, dp);
        
        return dp[i][prev+1][inc] = max(take, nonTake);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
