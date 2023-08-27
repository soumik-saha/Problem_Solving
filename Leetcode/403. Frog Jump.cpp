class Solution {
public:
    unordered_map<int, int> mark;
    int dp[2001][2001];

    bool canCross(vector<int>& stones) {
        for(int i=0; i<stones.size(); i++) {
            mark[stones[i]] = i;
        }    

        memset(dp, -1, sizeof(dp));
        return solve(stones, 0, 0);
    }

    int solve(vector<int>& arr, int i, int prev) {
        if(i==arr.size()-1)
            return 1;
        
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        
        int ans = false;

        for(int next=prev-1; next<=prev+1; next++) {
            if(next>0 && mark.find(arr[i]+next)!=mark.end())
                ans = ans || solve(arr, mark[arr[i]+next], next);
        }

        return dp[i][prev] = ans;
    }
};
