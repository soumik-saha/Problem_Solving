class Solution {
public:
    string reverseWords(string s) {
        vector<string> str;
        int n = s.size();
        string spl;
        for(int i=0; i<n; i++) {
            if(s[i]==' ') {
                reverse(spl.begin(), spl.end());
                str.push_back(spl);
                spl = "";
                continue;
            }
            spl += s[i];
        }
        reverse(spl.begin(), spl.end());
        str.push_back(spl);
        string ans;
        for(int i=0; i<str.size()-1; i++) {
            ans += str[i] + ' ';
        }
        ans += str[str.size()-1];

        return ans;
    }
};
