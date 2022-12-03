class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2;
        for(auto it: nums1)
            s1.insert(it);
        for(auto it: nums2)
            s2.insert(it);
        vector<int> ans;
        for(auto it1: s1){
            for(auto it2: s2){
                if(it1==it2)
                    ans.emplace_back(it1);
            }
        }
        return ans;
    }
};
