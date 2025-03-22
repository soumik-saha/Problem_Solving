//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for(int i=2; i<n-1; i++) {
            dp[i] = max(dp[i-2]+arr[i], dp[i-1]);
        }
        
        vector<int> dp2(n, 0);
        dp2[1] = arr[1];
        for(int i=2; i<n; i++) {
            dp2[i] = max(dp2[i-2]+arr[i], dp2[i-1]);
        }
        
        return max(dp2[n-1], dp[n-2]);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
