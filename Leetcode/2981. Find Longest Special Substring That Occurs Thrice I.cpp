class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string, int> count;
        int ans = -1;

        for(int i=0; i<n; i++) {
            string curr;
            for(int j=i; j<n; j++) {
                if(curr.empty() || curr.back()==s[j]) {
                    curr.push_back(s[j]);
                    count[curr]++;
                }
                else {
                    break;
                }
            }
        }

        for(auto it:count) {
            if(it.second>=3) {
                ans = max(ans, (int)(it.first.size()));
            }
        }

        return ans;
    }
};
