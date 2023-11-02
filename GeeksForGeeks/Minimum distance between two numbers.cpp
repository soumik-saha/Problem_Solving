//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here  
        vector<int> x1, y1;
        for(int i=0; i<n; i++) {
            if(a[i]==x) {
                x1.push_back(i);
            } 
            else if(a[i]==y) {
                y1.push_back(i);
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<x1.size(); i++) {
            for(int j=0; j<y1.size(); j++) {
                ans = min(ans, abs(y1[j]-x1[i]));
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends
