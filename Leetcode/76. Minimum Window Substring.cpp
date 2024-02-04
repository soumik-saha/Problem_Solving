class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0 || t.size()==0) {
            return "";
        }

        unordered_map<char, int> mp;
        for(int i=0; i<t.size(); i++) {
            mp[t[i]]++;
        }
        int required = mp.size();
        int l = 0, r = 0;

        int formed = 0;

        map<char, int> windowcnt;

        int ans[] = {-1, 0, 0};

        while(r<s.size()) {
            char c = s[r];
            windowcnt[c]++;

            if(mp.find(c)!=mp.end() && windowcnt[c]==mp[c]) {
                formed++;
            }

            while(l<=r && formed==required) {
                c = s[l];
                if(ans[0]==-1 || ans[0]>r-l+1) {
                    ans[0] = r-l+1;
                    ans[1] = l;
                    ans[2] = r;
                }

                windowcnt[c]--;
                if(mp.find(c)!=mp.end() && windowcnt[c]<mp[c]) {
                    formed--;
                }

                l++;
            }
            r++;
        }

        return ans[0]==-1 ? "" : s.substr(ans[1], ans[0]);
    }
};
