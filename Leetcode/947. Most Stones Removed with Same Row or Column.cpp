class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int ans = 0;
        int n = stones.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==j)    continue;
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]) {
                    adj[i].push_back(j);
                }
            }
        }
        int c = 0;
        vector<bool> vis(n, 0);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                c++;
            }
        }
        
        return n-c;
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
