//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> arr, int n, int m, int k) {
        int row = arr.size();
        int col = arr[0].size();
        
        vector<vector<int>> visited(row, vector<int>(col, -1));
        
        queue<vector<int>> q;
        
        q.push({0,0,0,k});
        
        while(q.empty() == false)
        {
            auto curr = q.front();
            q.pop();
            
            int x = curr[0];
            int y = curr[1];
            
            if(x < 0 || y < 0 || x >= row || y >= col)
                continue;
            
            if(x == row - 1 && y == col - 1)
                return curr[2];
            
            if(arr[x][y] == 1)
                if(curr[3] > 0)
                    curr[3]--;
                else
                    continue;
            
             if(visited[x][y] != -1 && visited[x][y] >= curr[3])
             {
                 continue;
             }
            
            visited[x][y] = curr[3];
            
            q.push({x+1, y, curr[2]+1, curr[3]});
            q.push({x-1, y, curr[2]+1, curr[3]});
            q.push({x, y+1, curr[2]+1, curr[3]});
            q.push({x, y-1, curr[2]+1, curr[3]});
            
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
