//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = arr[0];
        rightMax[n-1] = arr[n-1];
        
        for(int i=1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1], arr[i]);
        }
        
        for(int i=n-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], arr[i]);
        }
        
        int water = 0;
        for(int i=0; i<n; i++) {
            water += min(leftMax[i], rightMax[i]) - arr[i];
        }
        
        return water;
    }
    // 3 3 3 3 4 4 4 <-leftMax
    // 4 4 4 4 4 2 2 <-rightMax
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
