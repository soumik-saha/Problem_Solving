class Solution {
public:
    int maxUniqueSplit(string s) {
        int n = s.size();
        unordered_set<string> st;
        return solve(0, s, st);
    }
    int solve(int i, string& s, unordered_set<string>& st)  {
        int n = s.size();

        if(i==n) {
            return 0;
        }

        int ans = 0;

        string x;
        for(int ind=i; ind<n; ind++) {
            x+=s[ind];
            if(st.find(x)!=st.end())    continue;
            st.insert(x);
            ans = max(1+solve(ind+1, s, st), ans);
            st.erase(x);
        }
        
        return ans;
    }
};
