class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        vector<int> v(26,0);
        for(auto c:s) {
            v[c-'a']++;
        }

        string ans;
        int i = 25;
        while(i>=0) {
            if(v[i]==0) {
                i--;
                continue;
            }

            int posSize = min(repeatLimit, v[i]);
            v[i] -= posSize;
            
            while(posSize--) {
                ans.push_back(i+'a');
            }


            if(v[i]>0) {
                int idx = i-1;
                while(idx>=0 && v[idx]==0) {
                    idx--;
                }
                if(idx>=0) {
                    ans.push_back(idx+'a');
                    v[idx]--;
                }
                else {
                    break;
                }
                continue;
            }
        }

        return ans;
    }
};
