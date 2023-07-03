//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        int i=0, j=0, diff=0;
        vector<int> mn(n), mx(n);
        mn[i] = (arr[0]);
        mx[n-1] = (arr[n-1]);
        for(int i=1; i<n; i++) {
            mn[i] = min(mn[i-1], arr[i]);
            mx[n-i-1] = max(mx[n-i], arr[n-1-i]);
        }
        i=0, j=0;
        while(i<n && j<n) {
            while(j<n && mn[i]<=mx[j]) {
                j++;
            }
            diff = max(diff, j-i-1);
            i++;
        }
        return diff;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
