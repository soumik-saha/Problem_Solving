//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='1' && !vis[i][j]) {
                    dfs(i, j, grid, vis);
                    ans++;
                }
            }
        }
        
        return ans;
    }
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        int m = grid.size(), n = grid[0].size();
        if(i>=m || j>=n)    return;
        
        int dx[8] = {-1,0,1,1,1,0,-1,-1};
        int dy[8] = {-1,-1,-1,0,1,1,1,0};
        
        vis[i][j] = true;
        
        for(int k=0; k<8; k++) {
            int newX = i+dx[k];
            int newY = j+dy[k];
            
            if(newX>=0 && newY>=0 && newX<m && newY<n && vis[newX][newY]==false && grid[newX][newY]=='1') {
                dfs(newX, newY, grid, vis);
            }
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
