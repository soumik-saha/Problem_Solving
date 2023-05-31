//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        map<int,int> mp;
        int mini = INT_MAX;
        int res = INT_MIN;
        
        for(int i=0; i<n; i++) {
            if(mp[arr[i]]>=1)
                mp[arr[i]]++;
            else
                mp[arr[i]]= 1;
        }
        
        for(auto it: mp) {
            mini = min(mini, it.second);
        }
        
        
        for(auto it: mp) {
            if(it.second==mini)
                res = max(res, it.first);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends
