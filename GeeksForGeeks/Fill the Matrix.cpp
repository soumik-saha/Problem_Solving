//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        vector<vector<int>> adj(N+1, vector<int> (M+1, 0));
        adj[x][y] = 1;
        
        queue<pair<int, int>> q;
        q.push({x,y});
        
        int cnt = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i=0; i<size; i++) {
                int m = q.front().first;
                int n = q.front().second;
                
                q.pop();
                
                // UP
                if (m>1 && adj[m-1][n] == 0) {
                    q.push({m-1, n});
                    adj[m-1][n] = 1;
                }
                
                // LEFT
                if (n>1 && adj[m][n-1] == 0) {
                    q.push({m, n-1});
                    adj[m][n-1] = 1;
                }
                
                // RIGHT
                if(n<M && adj[m][n+1] == 0) {
                    q.push({m, n+1});
                    adj[m][n+1] = 1;
                }
                
                // DOWN
                if(m<N && adj[m+1][n] == 0) {
                    q.push({m+1, n});
                    adj[m+1][n] = 1;
                }
            }
            // COUNTING
            if (!q.empty()) {
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
