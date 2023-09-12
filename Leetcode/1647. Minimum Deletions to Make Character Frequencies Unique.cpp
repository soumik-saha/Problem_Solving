class Solution {
public:
    int minDeletions(string s) {
        int ans = 0, n = s.size();
        vector<int> v(26,0);
        unordered_set<int> freq;

        for(int i=0; i<n; i++) {
            v[s[i]-'a']++;
        }

        for(int i=0; i<26; i++) {
            while(v[i] && freq.find(v[i])!=freq.end()) {
                ans++;
                v[i]--;
            }
            freq.insert(v[i]);
        }

        return ans;
    }
};
