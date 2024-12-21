class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        dfs(0, -1, adj, values, k, ans);
        return ans;
    }
    int dfs(int curr, int parent, vector<vector<int>>& adj, vector<int>& values, int k, int& ans) {
        int sum = 0;
        for(auto nbr:adj[curr]) {
            if(nbr!=parent) {
                sum += dfs(nbr, curr, adj, values, k, ans);
                sum %= k;
            }
        }
        sum += values[curr];
        sum %= k;
        if(sum==0)  ans++;
        return sum;
    }
};
