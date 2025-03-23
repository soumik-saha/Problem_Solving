class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<long long, long long>>> adj(n);

        for(auto road:roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> count(n, 0);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;

        pq.push({0, 0});
        dist[0] = 0;
        count[0] = 1;

        while(!pq.empty()) {
            long long currTime = pq.top().first;
            long long currNode = pq.top().second;
            pq.pop();

            if(currTime>dist[currNode]) continue;

            for(auto& [nbr, time]:adj[currNode]) {
                long long newTime = currTime+time;

                if(newTime<dist[nbr]) {
                    dist[nbr] = newTime;
                    count[nbr] = count[currNode];
                    pq.push({newTime, nbr});
                }
                else if(newTime==dist[nbr]) {
                    count[nbr] = (count[nbr]+count[currNode]) % MOD;
                }
            }
        }

        return count[n-1];
    }
};
