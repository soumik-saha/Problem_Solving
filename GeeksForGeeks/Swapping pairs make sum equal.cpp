//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        sort(a, a+n);
        sort(b, b+m);
        
        int sumA = accumulate(a, a+n, 0);
        int sumB = accumulate(b, b+m, 0);
        
        int i=0, j=0;
        
        while(i<n && j<m) {
            int val1 = sumA - a[i] + b[j];
            int val2 = sumB - b[j] + a[i];
            
            if(val1==val2) {
                return 1;
            }
            else if(val1>val2) {
                i++;
            }
            else {
                j++;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
