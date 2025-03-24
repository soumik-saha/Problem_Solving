//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1, -1));
        return solve(0, arr.size()-1, arr, dp);
    }
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
        if(i+1==j)  return 0;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int res = INT_MAX;
        
        for(int k=i+1; k<j; k++) {
            res = min(res, solve(i, k, arr, dp) + solve(k, j, arr, dp) + arr[i]*arr[j]*arr[k]);
        }
        
        return dp[i][j] = res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends
