//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(V, 0);
        for(int node = 0; node<V; node++) {
            if(vis[node]==0 && solve(node, adj, vis, -1))  return true;
        }
        return false;
    }
    bool solve(int node, vector<vector<int>>& adj, vector<int>& vis, int parent) {
        vis[node] = 1;
        
        for(int nbr:adj[node]) {
            if(vis[nbr]==0) {
                vis[nbr] = 1;
                if(solve(nbr, adj, vis, node))
                    return true;
            }
            else if(vis[nbr]==1 && nbr!=parent)
                return true;
        }
        
        vis[node] = 2;
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
