//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code 
        if(e==0)    return 1.0;
        if(b==0)    return 0.0;
        
        if(e<0) {
            e = -e;
            b = 1/b;
        }
        
        double res = 1;
        while(e>0) {
            if(e%2==1) {
                res *= b;
            }
            
            b *= b;
            e /= 2;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
