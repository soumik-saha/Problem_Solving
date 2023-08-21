class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i=1; i<=s.size()/2; i++) {
            if(s.size()%i==0) {
                string pattern = "";
                for(int j=0; j<s.size()/i; j++) {
                    pattern += s.substr(0, i);
                }
                if(s == pattern)
                    return true;
            }

        }
        return false;
    }
};
