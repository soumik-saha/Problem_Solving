//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    const int MOD = 1e9+7;
    int padovanSequence(int n) {
        // code here.
        
        if(n<=2) {
            return 1;
        }
        
        int x = 1, y = 1, z = 1;
        
        for(int i=3; i<=n; i++) {
            int temp = (x + y) % MOD;
            x = y;
            y = z;
            z = temp;
        }
        
        return z;
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
