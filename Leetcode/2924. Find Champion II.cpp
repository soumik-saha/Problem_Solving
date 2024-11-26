class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int count = INT_MAX;
        vector<int> cnt(n, 0);
        for(int i=0; i<edges.size(); i++) {
            cnt[edges[i][1]]++;
        }
        vector<int> ans;
        for(int i=0; i<n; i++) {
            count = min(count, cnt[i]);
        }
        for(int i=0; i<n; i++) {
            if(cnt[i]==count) {
                ans.push_back(i);
            }
        }
        return ans.size()==1 ? ans[0]:-1;
    }
};
