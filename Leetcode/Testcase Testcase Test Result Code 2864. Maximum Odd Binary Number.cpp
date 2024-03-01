class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0;
        for(char c:s) {
            if(c=='1') {
                cnt1++;
            }
        }
        int n = s.size();
        for(int i=0; i<n-1; i++) {
            while((cnt1--)>1) {
                s[i++] = '1';
            }
            s[i] = '0';
        }
        s[n-1] = '1';
        return s;
    }
};
