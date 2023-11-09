class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        int ans = 0, cur = 0;

        for(int i=0; i<n; i++) {
            if(i==0 || s[i]==s[i-1]) {
                cur++;
            } else {
                cur = 1;
            }

            ans = (ans + cur) % MOD;
        }

        return ans;
    }
};
// T.C. -> O(N)
// S.C. -> O(1)
