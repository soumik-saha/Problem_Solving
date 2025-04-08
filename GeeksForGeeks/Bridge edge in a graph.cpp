//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto e:edges) {
            if((e[0]==c && e[1]==d) || (e[1]==c && e[0]==d)) continue;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> vis(V, false);
        int countComponents = 0;
        for(int node=0; node<V; node++) {
            if(!vis[node]) {
                countComponents++;
                dfs(node, adj, vis);
            }
        }
        
        for(auto e:edges) {
            if((e[0]==c && e[1]==d) || (e[1]==c && e[0]==d)){
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
                break;
            }
        }
        
        vis.assign(V, false);
        int count = 0;
        for(int node=0; node<V; node++) {
            if(!vis[node]) {
                count++;
                dfs(node, adj, vis);
            }
        }
        
        return count<countComponents;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        
        for(auto nbr:adj[node]) {
            if(!vis[nbr]) {
                dfs(nbr, adj, vis);
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
