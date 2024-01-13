class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp;

        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }

        for(int i=0; i<t.size(); i++) {
            if(mp[t[i]]>0) {
                mp[t[i]]--;
            }
        }

        int ans = 0;
        for(auto it : mp) {
            ans += it.second;
        }

        return ans;
    }
};
