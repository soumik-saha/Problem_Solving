class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> reachable(n);
        for (int node = 0; node < n; node++) {
            reachable[node] = dfs(node, adj, distanceThreshold);
        }
        for (int node : reachable) {
            cout << node << " ";
        }
        int ans = 0;
        int minReached = INT_MAX;
        for (int node = n - 1; node >= 0; node--) {
            if (minReached > reachable[node]) {
                minReached = reachable[node];
                ans = node;
            }
        }
        return ans;
    }
    int dfs(int node, vector<vector<pair<int, int>>>& adj, int distanceThreshold) {
        vector<int> dist(adj.size(), INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[node] = 0;
        pq.push({0, node});

        while(!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            for(auto nbr:adj[u]) {
                int v = nbr.first;
                int weight = nbr.second;
                if(d+weight<dist[v] && d+weight<=distanceThreshold) {
                    pq.push({d+weight, v});
                    dist[v] = d + weight;
                }
            }
        }

        int reachableCount = 0;
        for(auto d:dist) {
            if(d<=distanceThreshold) {
                reachableCount++;
            }
        }

        return reachableCount;
    }
};
