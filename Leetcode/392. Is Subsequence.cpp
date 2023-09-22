class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0, m = s.size(), n = t.size();
        for(int i=0; i<n; i++) {
            if(j<m && t[i]==s[j])
                j++;
        }
        if(j==m)    return true;
        return false;
    }
};
