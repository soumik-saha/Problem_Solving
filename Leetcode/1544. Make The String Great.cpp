class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        for(int i=1; i<s.size();) {
            if(s[i-1]!=s[i] && (toupper(s[i])==toupper(s[i-1]))) {
                s.erase(i-1, 2);
                if(i>1) {
                    i--;
                }
            }
            else {
                i++;
            }
        }
        return s;
    }
};
