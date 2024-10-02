class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) {
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end());
        int rank = 1;
        for(int i=0; i<n; i++) {
            int val = v[i].first;
            v[i].first = rank;
            while(i+1<n && v[i+1].first==val) {
                v[i+1].first = rank;
                i++;
            }
            rank++;
        }
        for(int i=0; i<n; i++) {
            arr[v[i].second] = v[i].first;
        }
        return arr;
    }
};
