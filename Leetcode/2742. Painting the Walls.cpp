class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memo = vector(n, vector(n+1, -1));
        return dp(0, n, cost, time);
    }
    int dp(int i, int rem, vector<int>& cost, vector<int>& time) {
        if(rem <= 0)    return 0;
        if(i==n)        return 1e9;

        if(memo[i][rem]!=-1)     return memo[i][rem];

        int paint = cost[i] + dp(i+1, rem-1-time[i], cost, time);
        int dontpaint = dp(i+1, rem, cost, time);

        return memo[i][rem] = min(paint, dontpaint);
    }
};
