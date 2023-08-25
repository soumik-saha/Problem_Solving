class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size(), b = s2.size();
        vector<vector<int>> memo(a+1, vector<int>(b+1, -1));
        int i=0, j=0, k=0;
        return solve(0, 0, 0, s1, s2, s3, memo);
    }
    bool solve(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>>& memo) {
        if(memo[i][j]!=-1) {
            return memo[i][j];
        }
        if(i==s1.size() && j==s2.size() && k==s3.size()) {
            return true;
        }

        bool x = false, y = false;
        if(i!=s1.size() && s1[i]==s3[k]) {
            x = solve(i+1, j, k+1, s1, s2, s3, memo);
        }
        if(j!=s2.size() && s2[j]==s3[k]) {
            y = solve(i, j+1, k+1, s1, s2, s3, memo);
        }

        return memo[i][j] = x || y;
    }
};
