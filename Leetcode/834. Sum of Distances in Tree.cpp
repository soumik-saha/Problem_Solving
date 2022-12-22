class Solution {
public:
    vector<unordered_set<int>> tree;
    vector<int> ans, cnt;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        ans.assign(n, 0);
        cnt.assign(n,1);

        for(auto edge : edges){
            tree[edge[0]].insert(edge[1]);
            tree[edge[1]].insert(edge[0]);
        }

        dfs1(0, -1);
        dfs2(0,-1);

        return ans;
    }

    void dfs1(int root, int pre){
        for(auto child : tree[root]){
            if(child == pre)
                continue;
            dfs1(child, root);
            cnt[root] += cnt[child];
            ans[root] += ans[child] + cnt[child];
        }
    }

    void dfs2(int root, int pre){
        for(auto child : tree[root]){
            if(child == pre)
                continue;
            ans[child] = ans[root] - cnt[child] + cnt.size() - cnt[child];
            dfs2(child, root);
        }
    }
};
