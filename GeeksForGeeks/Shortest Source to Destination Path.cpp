//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    struct Module {
      int x, y, dist;
      Module(int x, int y, int dist) {
          this->x = x;
          this->y = y;
          this->dist = dist;
      }
    };
    bool isSafe(vector<vector<int>>& mat, int x, int y) {
        return x>=0 && y>=0 && x<mat.size() && y<mat[0].size() && mat[x][y]!=0;
    }
    
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0) 
            return -1;
        
        int dirX[] = {0, 0, -1, 1};
        int dirY[] = {1, -1, 0, 0};
        
        queue<Module> q;
        q.push(Module(0, 0, 0));
        A[0][0] = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                Module curr = q.front();
                q.pop();
                int cx = curr.x;
                int cy = curr.y;
                int dist = curr.dist;
                
                if(cx==X && cy==Y)
                    return dist;
                
                for(int i=0; i<4; i++) {
                    int newX = cx+dirX[i];
                    int newY = cy+dirY[i];
                    if(isSafe(A, newX, newY)) {
                        A[newX][newY] = 0;
                        q.push(Module(newX, newY, dist+1));
                    }
                }
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
