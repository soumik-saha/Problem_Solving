//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> arr(n+1);
        arr[0]=0; arr[1]=1; arr[2]=2; arr[3]=3;
        for(int i=4; i<n+1; i++) {
            for(int k=2; k<=i; k++) {
                if(i%k==0){
                    arr[i] = k;
                    break;
                }
            }
        }
        return arr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends
