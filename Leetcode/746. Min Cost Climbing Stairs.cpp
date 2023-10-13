class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+2, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<=cost.size(); i++) {
            if(i<cost.size())
                dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
            else {
                dp[i] = min(dp[i-1], dp[i-2]);
            }
        }
        return dp[cost.size()];
    }
};
