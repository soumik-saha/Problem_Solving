class Solution {
public:
    bool halvesAreAlike(string s) {
        int vcnt1 = 0, vcnt2 = 0;
        for(int i=0; i<s.size(); i++) {
            if(i<s.size()/2) {
                if(isVowel(s[i])) {
                    vcnt1++;
                }
            }
            else {
                if(isVowel(s[i])) {
                    vcnt2++;
                }
            }
        }

        return vcnt1 == vcnt2;
    }

    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }

        return false;
    }
};
