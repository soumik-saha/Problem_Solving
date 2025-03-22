class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        int count = 0;

        for(int node=0; node<n; node++) {
            if(!visited[node]) {
                int nodeCount = 0, edgeCount = 0;
                dfs(node, adj, visited, nodeCount, edgeCount);
                if(edgeCount/2==nodeCount*(nodeCount-1)/2) {
                    count++;
                }
            }
        }

        return count;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int &nodeCount, int &edgeCount) {
        visited[node] = true;
        nodeCount++;

        for(auto nbr:adj[node]) {
            edgeCount++;
            if(!visited[nbr]) {
                dfs(nbr, adj, visited, nodeCount, edgeCount);
            }
        }
    }
};
