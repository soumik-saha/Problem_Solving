//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        vector<string> ans;
        string path;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        solve(0, 0, mat, path, vis, ans);
        return ans;
    }
    void solve(int i, int j, vector<vector<int>>& mat, string path, vector<vector<bool>>& vis, vector<string>& ans) {
        int n = mat.size();
        
        if(i>=n || j>=n || i<0 || j<0 || mat[i][j] == 0 || vis[i][j]) {
            return;
        }
        
        if(i==n-1 && j==n-1) {
            ans.push_back(path);
            return;
        }
        
        vis[i][j] = true;
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        for(int k=0; k<4; k++) {
            int newX = i+dx[k];
            int newY = j+dy[k];
            
            if(newX<n && newY<n && newX>=0 && newY>=0 && !vis[newX][newY]) {
                switch(k) {
                    case 0:
                        path.push_back('R');
                        break;
                    case 1:
                        path.push_back('D');
                        break;
                    case 2:
                        path.push_back('L');
                        break;
                    case 3:
                        path.push_back('U');
                        break;
                }
                solve(newX, newY, mat, path, vis, ans);
                path.pop_back();
            }
        }
        
        vis[i][j] = false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
