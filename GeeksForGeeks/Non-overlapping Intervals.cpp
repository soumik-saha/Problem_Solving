//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& x, const vector<int>& y) {
            return x[1]<y[1];
        });
        
        int ans = 0;
        int lastEnd = intervals[0][1];
        for(int i=1; i<n; i++) {
            if(lastEnd<=intervals[i][0]) {
                lastEnd = intervals[i][1];
            }
            else {
                ans++;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
