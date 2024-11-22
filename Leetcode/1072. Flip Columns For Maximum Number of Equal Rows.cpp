class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        for(auto x:matrix) {
            string s = "";
            int top = x[0];
            for(int i=0; i<x.size(); i++) {
                if(x[i]==top) {
                    s += '1';
                }
                else {
                    s += '0';
                }
            }
            mp[s]++;
        }
        int ans = 0;
        for(auto it:mp) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};
