class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }
        for (auto q : queries) {
            adj[q[0]].push_back(q[1]);
            ans.push_back(bfs(n, adj));
        }
        return ans;
    }
    int bfs(int n, vector<vector<int>>& adj) {
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int ans = 0;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto node = q.front();
                q.pop();
                if(node==n-1) {
                    return ans;
                }
                for(auto nbr:adj[node]) {
                    if(!vis[nbr]) {
                        q.push(nbr);
                        vis[nbr] = true;
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};
