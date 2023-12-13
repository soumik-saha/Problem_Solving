//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    const int MOD = 1e9 + 7;
	    ll int zeroending = 1, oneending = 1;
	    ll int sum = zeroending + oneending;
	    
	    int i = 2;
	    while(i<=n) {
	        oneending = zeroending;
	        zeroending = sum;
	        
	        sum = (oneending + zeroending) % MOD;
	        i++;
	    }
	    
	    return sum % MOD;
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
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
