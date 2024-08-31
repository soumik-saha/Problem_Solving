class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while(!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node==end_node) {
                return prob;
            }

            for(auto& [nbr, edgeProb]:adj[node]) {
                double newProb = edgeProb*prob;
                if(newProb>maxProb[nbr]) {
                    maxProb[nbr] = newProb;
                    pq.push({newProb, nbr});
                }
            }
        }

        return 0.0;
    }
    
};
