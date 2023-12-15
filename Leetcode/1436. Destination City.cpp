class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool> mp;
        for(int i=0; i<paths.size(); i++) {
            mp[paths[i][0]] = true;
        }
        for(int i=0; i<paths.size(); i++) {
            if(mp.find(paths[i][1]) == mp.end()) {
                return paths[i][1];
            }
        }
        return "";
    }
};
