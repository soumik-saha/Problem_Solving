//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        int n = arr.size();
        vector<string> original = arr;
        vector<vector<string>> ans;
        for(int i=0; i<n; i++) {
            sort(arr[i].begin(), arr[i].end());
        }
        vector<vector<int>> idx;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) {
            if(vis[i]==1)   continue;
            vector<int> ind;
            for(int j=0; j<n; j++) {
                if(vis[j]==1)   continue;
                if(arr[i]==arr[j]) {
                    ind.push_back(j);
                    vis[j] = 1;
                }
            }
            idx.push_back(ind);
        }
        for(int i=0; i<idx.size(); i++) {
            vector<string> row;
            for(int j=0; j<idx[i].size(); j++) {
                row.push_back(original[idx[i][j]]);
            }
            ans.push_back(row);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
