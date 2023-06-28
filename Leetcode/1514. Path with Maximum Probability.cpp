typedef pair<int, double> pid;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pid>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double pathProb = succProb[i];

            graph[u].push_back(pid(v, pathProb));
            graph[v].push_back(pid(u, pathProb));
        }

        vector<double> maxProb(n);
        maxProb[start] = 1.0;

        // sort the queue such that the highest probability is at the top
        auto compare = [](const pid& a, const pid& b) { return a.second < b.second; };
        priority_queue<pid, vector<pid>, decltype(compare)> pq(compare);
        pq.push(pid(start, 1.0));

        while (!pq.empty()) {
            auto [curNode, curProb] = pq.top();
            pq.pop();

            if (curNode == end) return curProb;

            for (pid& next : graph[curNode]) {
                int nxtNode = next.first;
                double pathProb = next.second;
                double nextProb = curProb * pathProb;
                if (nextProb > maxProb[nxtNode]) {
                    maxProb[nxtNode] = nextProb;
                    pq.push(pid(nxtNode, maxProb[nxtNode]));
                }
            }
        }

        return 0.0;
    }
};
