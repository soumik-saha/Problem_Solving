//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        const int MOD = 1e9 + 7;
        long long int res = 1;
        int negMax = INT_MIN;
        int n = arr.size();
        
        for(int it:arr) {
            if(it<0) {
                negMax = max(negMax, it);
            }
            if(it!=0) {
                res = (res * it) % MOD;
            }
        }
        if(res<0 && negMax!=INT_MIN) {
            res = (res / negMax) % MOD;
        }
        else if (res<0 && negMax==INT_MIN)  {
            res = 0;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
