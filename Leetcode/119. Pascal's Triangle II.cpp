class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1, 1);
        if(rowIndex <= 1) return dp;
        vector<int> temp = dp;
        for(int i = 2; i <= rowIndex; i++) {
            for(int j = 1; j < i; j++) {
                temp[j] = dp[j] + dp[j-1];
            }
            dp = temp;
        }
        return dp;
    }
};
