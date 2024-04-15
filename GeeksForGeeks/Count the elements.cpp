//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        // Your code goes here;
        int maxEle = INT_MIN;
        for(int i=0; i<n; i++) {
            maxEle = max(maxEle, max(a[i], b[i]));
        }
        vector<int> dp(maxEle+1, 0);
        
        for(int i=0; i<n; i++) {
            dp[b[i]]++;
        }
        
        for(int i=1; i<=maxEle; i++) {
            dp[i]  = dp[i-1] + dp[i];
        }
        
        vector<int> res;
        
        for(int i=0; i<q; i++) {
            res.push_back(dp[a[query[i]]]);
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
