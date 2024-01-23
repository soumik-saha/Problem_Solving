class Solution {
public:
    int ans = 0;
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        solve(0, arr, n, "");
        return ans;
    }
    void solve(int i, vector<string>& arr, int n, string s) {
        ans = max(ans, static_cast<int>(s.size()));

        for(int ind=i; ind<n; ind++) {
            if(!validity(s, arr[ind]))  continue;
            solve(ind+1, arr, n, s+arr[ind]);
        }
    }
    bool validity(string curs, string news) {
        unordered_set<char> st;
        for(char ch:news) {
            if(st.count(ch)>0) {
                return false;
            }
            st.insert(ch);
            if(curs.find(ch)!=string::npos) {
                return false;
            }
        }
        return true;
    }
};
