class Solution {
private:
    void solve(int ind, int n, int k, vector<int>& ds, vector<vector<int>>& ans) {
        if(ind-1 > n) {
            return;
        }
        
        if(ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        
        // Take
        ds.push_back(ind);
        solve(ind+1, n, k, ds, ans);
        
        // Leave
        ds.pop_back();
        solve(ind+1, n, k, ds, ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1, n, k, ds, ans);
        return ans;
    }
};
