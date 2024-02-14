//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void dfs(int u, int parent, int &time, vector<int> &low, vector<int> &disc, vector<vector<int>> &adj, vector<vector<int>> &result) {
        disc[u] = low[u] = time++;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (disc[v] == -1) {
                dfs(v, u, time, low, disc, adj, result);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    result.push_back({min(u, v), max(u, v)});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int v, vector<int> adj[]) {
        vector<vector<int>> result;
        vector<int> disc(v, -1), low(v, -1);
        vector<vector<int>> adjList(v);
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < adj[i].size(); ++j) {
                adjList[i].push_back(adj[i][j]);
            }
        }
        int time = 0;
        for (int i = 0; i < v; ++i) {
            if (disc[i] == -1) {
                dfs(i, -1, time, low, disc, adjList, result);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends
