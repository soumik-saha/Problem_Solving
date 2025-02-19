class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> ans;

        string ds;
        solve(n, ds, ans);

        return ans.size()<k ? "" : ans[k-1];
    }
    void solve(int n, string& ds, vector<string>& ans) {
        if(n==0) {
            ans.push_back(ds);
            return;
        }

        for(char i='a'; i<='c'; i++) {
            if(!ds.empty() && ds.back()==i) continue;
            ds.push_back(i);
            solve(n-1, ds, ans);
            ds.pop_back();
        }
    }
};
