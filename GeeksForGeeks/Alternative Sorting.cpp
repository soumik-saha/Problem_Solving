//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> ans(n);
        int i = 1, j = 0;
        while(i<n && j<n) {
            ans[i] = arr[j++];
            i+=2;
        }
        if(i==n+1)
            i=n-2;
        else
            i=n-1;
        while(i>=0 && j<n) {
            ans[i] = arr[j++];
            i-=2;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
