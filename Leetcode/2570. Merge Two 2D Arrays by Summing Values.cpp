class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size(), n = nums2.size();
        map<int, int> mp;
        for(auto num:nums1) {
            mp[num[0]] += num[1];
        }
        for(auto num:nums2) {
            mp[num[0]] += num[1];
        }
        vector<vector<int>> ans;
        for(auto [id, val]:mp) {
            ans.push_back({id, val});
        }
        return ans;
    }
};
