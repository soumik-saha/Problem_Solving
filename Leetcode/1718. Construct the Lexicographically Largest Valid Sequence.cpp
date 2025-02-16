class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1, 0);
        vector<bool> vis(n+1, false);
        solve(0, ans, vis, n);
        return ans;
    }
    bool solve(int idx, vector<int>& ans, vector<bool>& vis, int n) {
        if(idx==ans.size()) return true;
        if(ans[idx]!=0) return solve(idx+1, ans, vis, n);
        else {
            for(int i=n; i>=1; i--) {
                if(vis[i])  continue;
                vis[i] = true;
                ans[idx] = i;
                if(i==1) {
                    if(solve(idx+1, ans, vis, n))   return true;
                }
                else if(idx+i<ans.size() && ans[idx+i]==0) {
                    ans[idx+i] = i;
                    if(solve(idx+1, ans, vis, n))   return true;
                    ans[idx+i] = 0;
                }

                vis[i] = false;
                ans[idx] = 0;
            }
        }
        return false;
    }
};
