class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        for(int i=1; i<s.size(); i++) {
            int zeros = 0, ones = 0;
            for(int j=0; j<i; j++) {
                if(s[j]=='0') {
                    zeros++;
                }
            }
            for(int j=i; j<s.size(); j++) {
                if(s[j]=='1') {
                    ones++;
                }
            }
            ans = max(ans, zeros+ones);
        }
        return ans;
    }
};
