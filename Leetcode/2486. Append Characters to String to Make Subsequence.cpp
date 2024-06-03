class Solution {
public:
    int appendCharacters(string s, string t) {
        int first = 0, longestPrefix = 0;

        while(first<s.size() && longestPrefix<t.size()) {
            if(s[first] == t[longestPrefix]) {
                longestPrefix++;
            }
            first++;
        }

        return t.size() - longestPrefix;
    }
};
