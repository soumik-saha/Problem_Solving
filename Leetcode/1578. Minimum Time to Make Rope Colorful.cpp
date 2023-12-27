class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<int> dp(colors.size(), 0);
        int prevInd = 0;
        for(int i=1; i<colors.size(); i++) {
            int time = 0;
            int oldPrevInd = prevInd;
            if(colors[prevInd]==colors[i]) {
                time = min(neededTime[prevInd], neededTime[i]);
                if(neededTime[i]<=neededTime[prevInd]) {
                    colors[i] = 'x';
                }
                else {
                    colors[prevInd] = 'x';
                    prevInd = i;
                }
                
            } else {
                prevInd = i;
            }
            dp[i] = dp[i-1] + time;
        }
        return dp[colors.size()-1];
    }
};
