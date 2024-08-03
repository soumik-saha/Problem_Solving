//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        for(int j=0; j<mat.size(); j++) {
            int known = 0;
            for(int i=0; i<mat[0].size(); i++) {
                if(i!=j && mat[i][j]==1) {
                    known++;
                }
            }
            if(known==mat.size()-1) {
                int know = 0;
                for(int i=0; i<mat[0].size(); i++) {
                    if(i!=j && mat[j][i]==1) {
                        know++;
                    }
                }
                if(know==0) return j;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends
