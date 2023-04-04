class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen (26,-1);
        int cnt = 1, substrStart = 0; 
        for(int i=0; i<s.size(); i++) {
            if(lastSeen[s[i]-'a']>=substrStart) {
                cnt++;
                substrStart = i;
            }
            lastSeen[s[i]-'a'] = i;
        }
        return cnt;
    }
};
