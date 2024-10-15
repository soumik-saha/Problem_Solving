class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long ans = 0;
        long long black = 0;
        for(char c:s) {
            if(c=='1') {
                black++;
            }
            if(c=='0') {
                ans += black;
            }
        }
        return ans;
    }
};
