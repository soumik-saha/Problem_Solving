class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int it : nums) {
            mp[it]++;
        }
        int res = 0;
        for(auto it : mp) {
            res += ((it.second * (it.second - 1)) / 2);
        }
        return res;
    }
};
