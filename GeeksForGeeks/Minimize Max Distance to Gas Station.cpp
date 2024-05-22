//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool isPossible(vector<int>& stations, int k, double maxDist) {
        int count = 0;
        for (int i = 1; i < stations.size(); i++) {
            count += ceil((stations[i] - stations[i - 1]) / maxDist) - 1;
        }
        return count <= k;
    }
    
    double findSmallestMaxDist(vector<int> &stations, int k) {
        double low = 0, high = 1e9;
        while (high - low > 1e-6) {
            double mid = (low + high) / 2;
            if (isPossible(stations, k, mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return high;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends
