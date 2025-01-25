class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> valueIdxPairs;
        for(int i=0; i<n; i++) {
            valueIdxPairs.push_back({nums[i], i});
        }
        sort(valueIdxPairs.begin(), valueIdxPairs.end());
        vector<vector<pair<int, int>>> groups;
        groups.push_back({valueIdxPairs[0]});
        for(int i=1; i<n; i++) {
            if(valueIdxPairs[i].first-valueIdxPairs[i-1].first<=limit) {
                groups.back().push_back(valueIdxPairs[i]);
            }
            else {
                groups.push_back({valueIdxPairs[i]});
            }
        }
        for(auto group:groups) {
            vector<int> indices;
            for(auto [val, idx]:group) {
                indices.push_back(idx);
            }
            sort(indices.begin(), indices.end());
            for(int i=0; i<indices.size(); i++) {
                nums[indices[i]] = group[i].first;
            }
        }
        return nums;
    }
};
