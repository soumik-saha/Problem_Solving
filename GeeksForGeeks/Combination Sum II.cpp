//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(), arr.end());
        solve(0, arr, n, k, ds, ans);
        return ans;
    }
    void solve(int start, vector<int> arr,int n,int k, vector<int>& ds, vector<vector<int>>& ans) {
        if(k==0) {
            ans.push_back(ds);
        }
        for (int i = start; i < arr.size() && arr[i] <= k; i++) {
            // Avoid duplicates
            if (i > start && arr[i] == arr[i - 1]) continue;

            ds.push_back(arr[i]);
            solve(i + 1, arr, n, k - arr[i], ds, ans);
            ds.pop_back();
        }
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
