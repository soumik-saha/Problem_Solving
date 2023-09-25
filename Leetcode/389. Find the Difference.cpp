class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        for(auto i: s) {
            freq1[i-'a']++;
        }
        for(auto i: t) {
            freq2[i-'a']++;
        }
        for(int i=0; i<t.size(); i++) {
            if(i<s.size() && freq1[s[i]-'a'] != freq2[s[i]-'a']) 
                return s[i];
            if(freq1[t[i]-'a'] == 0 && freq2[t[i]-'a'] > 0) 
                return t[i];
        }
        return '0';
    }
};
