class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        vector<char> ch;
        for (auto it : mp) {
            if (it.second > 1) {
                ch.push_back(it.first);
            }
        }

        int ans = -1;
        for(int i=0; i<ch.size(); i++) {
            int first = 0, last = 0;
            for(int j=0; j<s.size(); j++) {
                if(s[j]==ch[i]) {
                    first = j;
                    break;
                }
            }
            for(int j=s.size()-1; j>=0; j--) {
                if(s[j]==ch[i]) {
                    last = j;
                    break;
                }
            }
            ans = max(ans, last-first-1);
        }

        return ans;
    }
};
