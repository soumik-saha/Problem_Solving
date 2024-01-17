//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> ans;
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>> s;
        
        solve(0, s, arr, n);
        for(auto it : s) {
            ans.push_back(it);
        }
        
        return ans;
    }
    
    void solve(int i, set<vector<int>>& s, vector<int>& arr, int n) {
        if(i==n) {
            s.insert(arr);
            return;
        }
        
        for(int ind=i; ind<n; ind++) {
            swap(arr[i], arr[ind]);
            solve(i+1, s, arr, n);
            swap(arr[i], arr[ind]);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
