class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp1, mp2;
        for(int it:arr) {
            mp1[it]++;
        }
        for(int it:target) {
            mp2[it]++;
        }
        for(auto it:mp1) {
            if(mp2[it.first]!=mp1[it.first]) {
                return false;
            }
        }
        return true;
    }
};
