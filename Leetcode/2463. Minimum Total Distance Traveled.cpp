class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int r = robot.size(), f = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factPos;
        for(auto f:factory) {
            for(int i=0; i<f[1]; i++) {
                factPos.push_back(f[0]);
            }
        }
        vector<vector<long long>> dp(r+1, vector<long long>(factPos.size()+1,-1));
        return solve(0, 0, robot, factPos, dp);
    }
    long long solve(int i, int j, vector<int>& robot, vector<int>& factory, vector<vector<long long>>& dp) {
        if(i==robot.size()) {
            return 0;
        }

        if(j==factory.size()) {
            return 1e12;
        }

        if(dp[i][j]!=-1)    return dp[i][j];

        long long take = abs(robot[i]-factory[j]) + solve(i+1, j+1, robot, factory, dp);

        long long leave = solve(i, j+1, robot, factory, dp);

        return dp[i][j] = min(take, leave);
    }
};
