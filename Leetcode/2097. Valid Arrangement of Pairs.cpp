class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> adj;
        unordered_map<int, int> indeg, outdeg;

        for(auto pair:pairs) {
            int start = pair[0], end = pair[1];
            adj[start].push_back(end);
            outdeg[start]++;
            indeg[end]++;
        }

        int start = -1;
        for(auto node:adj) {
            int i = node.first;
            if(outdeg[i]-indeg[i]==1) {
                start = i;
                break;
            }
        }

        if(start==-1) {
            start = pairs[0][0];
        }

        vector<int> ans;

        function<void(int)> visit = [&](int node) {
            while(!adj[node].empty()) {
                int nextNode = adj[node].front();
                adj[node].pop_front();
                visit(nextNode);
            }
            ans.push_back(node);
        };

        visit(start);

        reverse(ans.begin(), ans.end());

        vector<vector<int>> res;
        for(int i=1; i<ans.size(); i++) {
            res.push_back({ans[i-1], ans[i]});
        }

        return res;
    }
};
