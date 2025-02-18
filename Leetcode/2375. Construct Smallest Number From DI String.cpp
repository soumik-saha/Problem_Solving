class Solution {
public:
    string smallestNumber(string pattern) {
        string num;
        for(int i=0; i<=pattern.size(); i++) {
            num += '9';
        }
        for(char i='1'; i<='9'; i++) {
            string curr;
            curr += i;
            vector<bool> vis(10, false);
            vis[i-'0'] = true;
            if(solve(0, curr, pattern, vis)) {
                num = min(num, curr);
            }
        }
        return num;
    }
    bool solve(int i, string& curr, string& pattern, vector<bool>& vis) {
        if(i==pattern.size()) {
            return true;
        }
        
        if(pattern[i]=='I')
            for(char c=curr.back()+1; c<='9'; c++) {
                if(vis[c-'0'])  continue;
                vis[c-'0'] = true;
                curr += c;
                if(solve(i+1, curr, pattern, vis))  return true;
                curr.pop_back();
                vis[c-'0'] = false;
            }
        else
            for(char c=curr.back()-1; c>='1'; c--) {
                if(vis[c-'0'])  continue;
                vis[c-'0'] = true;
                curr += c;
                if(solve(i+1, curr, pattern, vis))  return true;
                curr.pop_back();
                vis[c-'0'] = false;
            }

        return false;
    }
};
