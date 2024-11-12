class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        for(auto q:queries) {
            items.push_back({q, 0});
        }

        int n = items.size();

        sort(items.begin(), items.end());

        unordered_map<int, int> v;
        v[items[0][0]] = items[0][1];

        for(int i=1; i<n; i++) {
            items[i][1] = max(items[i][1], items[i-1][1]);
            v[items[i][0]] = max(v[items[i][0]], items[i][1]);
        }

        vector<int> ans;

        for(auto q:queries) {
            ans.push_back(v[q]);
        }

        return ans;
    }
};
