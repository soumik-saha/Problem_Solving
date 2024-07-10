//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        // int n = mat.size();
        // int m = mat[0].size();
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 || j==0) {
                    continue;
                }
                if(mat[i][j]==1) {
                    mat[i][j] = min({mat[i-1][j-1], mat[i-1][j], mat[i][j-1]}) + 1;
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                // cout<<mat[i][j]<<" ";
                ans = max(ans, mat[i][j]);
            }
            // cout<<endl;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends
