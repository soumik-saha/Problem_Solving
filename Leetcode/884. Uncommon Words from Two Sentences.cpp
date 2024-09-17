class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> st1, st2;
        int start = 0;
        vector<string> ans;

        for(int i=0; i<s1.size(); i++) {
            start = i;
            while(i<s1.size() && s1[i]!=' ') {
                i++;
            }
            st1[s1.substr(start, i-start)]++;
        }

        for(int i=0; i<s2.size(); i++) {
            start = i;
            while(i<s2.size() && s2[i]!=' ') {
                i++;
            }
            st2[s2.substr(start, i-start)]++;
        }

        for(auto [it, xnt]:st1) {
            if(xnt==1 && st2.find(it)==st2.end()) {
                ans.push_back(it);
            }
        }

        for(auto [it,xnt]:st2) {
            if(xnt==1 && st1.find(it)==st1.end()) {
                ans.push_back(it);
            }
        }

        return ans;
    }
};
