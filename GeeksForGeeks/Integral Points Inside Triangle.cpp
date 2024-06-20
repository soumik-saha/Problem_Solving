//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        // code here
        long x1 = p[0];
        long x2 = q[0];
        long x3 = r[0];
        long y1 = p[1];
        long y2 = q[1];
        long y3 = r[1];
        
        long area = abs((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2)));
        
        long B1 = __gcd(abs(x1-x2), abs(y1-y2));
        long B2 = __gcd(abs(x2-x3), abs(y2-y3));
        long B3 = __gcd(abs(x3-x1), abs(y3-y1));
        
        long B = B1+B2+B3;
        
        long internalPoints = (area-B+2)/2;
        
        return internalPoints;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends
