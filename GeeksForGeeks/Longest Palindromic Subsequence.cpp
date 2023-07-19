//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        int n = A.length();
        string B(A.rbegin(),A.rend()); 
        vector<int> prev(n+1),curr(n+1);
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(A[i-1] == B[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(curr[j-1],prev[j]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
