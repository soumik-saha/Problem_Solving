//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(N, INT_MAX);
        vector<bool> vis(N, false);
        solve(src, adj, vis, 0, ans);
        for(int &it:ans) {
            if(it==INT_MAX) {
                it = -1;
            }
        }
        return ans;
    }
    void solve(int src, vector<vector<int>>& adj, vector<bool> vis, int curr, vector<int>& ans) {
        queue<int> q;
        q.push(src);
        ans[src] = 0;
        vis[src] = true;
        int level = 0;
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                int node = q.front();
                q.pop();
                ans[node] = level;
                for(auto nbr:adj[node]) {
                    if(!vis[nbr]) {
                        vis[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            level++;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
