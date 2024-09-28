//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n, 0);
        // dp[0] = arr[0];
        for(int i=1; i<n; i++) {
            int curr = INT_MAX;
            int j = i-1;
            int l = k;
            while(j>=0 && l>0) {
                curr = min(curr, dp[j] + abs(arr[i]-arr[j]));
                j--;
                l--;
            }
            dp[i] = curr;
        }
        return dp[n-1];
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
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
