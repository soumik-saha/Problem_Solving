class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[150] = {0}, ans = 0;
        for(auto i:s) {
            for(int j=i-k; j<=i+k; j++) {
                dp[i] = max(dp[i], dp[j]);
            }
            ans = max(ans, ++dp[i]);
        }
        return ans;
    }
};
