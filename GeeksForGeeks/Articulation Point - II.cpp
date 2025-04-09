//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(V, false);
        vector<int> tin(V, -1), low(V, -1);
        vector<bool> isArticulation(V, false);
        int timer = 0;
        
        for(int i=0; i<V; i++) {
            if(vis[i]==false) {
                dfs(i, -1, adj, vis, tin, low, timer, isArticulation);
            }
        }

        vector<int> ans;
        for(auto i=0; i<V; i++) {
            if(isArticulation[i]) {
                ans.push_back(i);
            }
        }
        
        if(ans.empty()) ans.push_back(-1);
        return ans;
    }
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& tin, vector<int>& low, int& timer, vector<bool>& isArticulation) {
        vis[node] = true;
        tin[node] = low[node] = timer++;
        int children = 0;
        
        for(auto nbr:adj[node]) {
            if(nbr==parent) continue;
            if(!vis[nbr]) {
                dfs(nbr, node, adj, vis, tin, low, timer, isArticulation);
                low[node] = min(low[node], low[nbr]);
                if(low[nbr]>=tin[node] && parent!=-1) {
                    isArticulation[node] = true;
                }
                children++;
            }
            else {
                low[node] = min(low[node], tin[nbr]);
            }
        }
        
        if(parent==-1 && children>1) {
            isArticulation[node] = true;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
