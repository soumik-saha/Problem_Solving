class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m = trust.size();
        unordered_map<int, int> mp, mp2;
        for(int i=0; i<m; i++) {
            mp[trust[i][0]]++;
            mp2[trust[i][1]]++;
        }
        for(int i=0; i<n; i++) {
            if(mp.find(i+1)==mp.end() && mp2[i+1]==n-1) {
                return i+1;
            }
        }
        return -1;
    }
};
