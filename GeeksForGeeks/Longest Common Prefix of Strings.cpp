//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string ans = "";
        bool flag = true;
        int minSize = INT_MAX;
        
        for(auto it:arr) {
            minSize = min(minSize, (int)it.size());
        }
        
        for(int i=0; i<minSize; i++) {
            char ch = arr[0][i];
            for(int j=0; j<arr.size(); j++) {
                if(arr[j][i]!=ch) {
                    flag = false;
                    break;
                }
            }
            if(!flag)   break;
            ans.push_back(arr[0][i]);
        }
        
        return ans=="" ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends
