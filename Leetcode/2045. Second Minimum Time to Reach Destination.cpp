class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);

        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, int>> q;
        vector<int> dist1(n+1, INT_MAX), dist2(n+2, INT_MAX), freq(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        dist1[1] = 0;
        
        while(!pq.empty()) {
            auto [timeTaken, node] = pq.top();
            pq.pop();

            freq[node]++;

            if(freq[node]==2 && node==n) {
                return timeTaken;
            }

            if((timeTaken/change)%2) {
                timeTaken = change * (timeTaken/change + 1) + time;
            } else {
                timeTaken = timeTaken + time;
            }

            for(auto nbr:adj[node]) {
                if(freq[nbr]==2)    continue;

                if(dist1[nbr]>timeTaken) {
                    dist2[nbr] = dist1[nbr];
                    dist1[nbr] = timeTaken;
                    pq.push({timeTaken, nbr});
                }
                else if(dist2[nbr]>timeTaken && dist1[nbr]!=timeTaken) {
                    dist2[nbr] = timeTaken;
                    pq.push({timeTaken, nbr});
                }
            }
        }
        return 0;
    }
};
