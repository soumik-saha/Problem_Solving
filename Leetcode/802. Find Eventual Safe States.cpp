class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++) {
            for(auto node: graph[i]) {
                adj[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> safe(n);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = 1;

            for(auto neighbour :  adj[node]) {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                    q.push(neighbour);
            }
        }

        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(safe[i])
                ans.push_back(i);
        }

        return ans;
    }
};
