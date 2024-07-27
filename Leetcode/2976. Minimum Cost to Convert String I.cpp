class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        unordered_map<char, vector<pair<char, int>>> adj;
        for(int i=0; i<n; i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }
        unordered_map<char, unordered_map<char, int>> minCost;
        for(char ch='a'; ch<='z'; ch++) {
            if(adj.find(ch)!=adj.end()) {
                dijkstra(ch, adj, minCost);
            }
        }
        long long ans = 0;
        for(int i = 0; i < source.size(); i++) {
            if(source[i] == target[i]) continue;
            if(minCost[source[i]].find(target[i]) == minCost[source[i]].end()) {
                return -1;
            }
            ans += minCost[source[i]][target[i]];
        }
        return ans;
    }
    void dijkstra(char start, unordered_map<char, vector<pair<char, int>>>& adj, unordered_map<char, unordered_map<char, int>>& minCost) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        pq.push({0, start});
        minCost[start][start] = 0;

        while(!pq.empty()) {
            char u = pq.top().second;
            int currCost = pq.top().first;
            pq.pop();

            if(currCost>minCost[start][u])  continue;

            for(auto& nbr:adj[u]) {
                char v = nbr.first;
                int weight = nbr.second;
                int newCost = currCost + weight;

                if(minCost[start].find(v)==minCost[start].end() || newCost<minCost[start][v]) {
                    minCost[start][v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }
    }
};
