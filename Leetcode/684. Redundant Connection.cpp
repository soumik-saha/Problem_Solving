class Solution {
public:
    vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }
        for(auto edge:edges) {
            int f1 = find(edge[0]);
            int f2 = find(edge[1]);
            if(f1==f2)  return edge;
            parent[f1] = f2;
        }
        return {};
    }
    int find(int x) {
        return parent[x]==x ? x : find(parent[x]);
    }
};
