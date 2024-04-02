class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp, mp2;
        int n = s.size(), m = t.size();
        if(n!=m)    return false;
        for(int i=0; i<n; i++) {
            if(mp.find(s[i])!=mp.end() && mp[s[i]]!=t[i]) {
                return false;
            }
            else {
                mp[s[i]] = t[i];
            }
        }
        for(int i=0; i<n; i++) {
            if(mp2.find(t[i])!=mp2.end() && mp2[t[i]]!=s[i]) {
                return false;
            }
            else {
                mp2[t[i]] = s[i];
            }
        }
        return true;
    }
};
