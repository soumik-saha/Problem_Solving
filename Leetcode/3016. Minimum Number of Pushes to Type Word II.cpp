class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<char, int> freq;
        for(char c:word) {
            freq[c]++;
        }
        vector<pair<int, int>> v;
        for(auto &[key, val] : freq) {
            v.push_back({val, key});
        }
        sort(v.rbegin(), v.rend());
        int keyId = 2;
        int push = 1;
        int ans = 0;
        for(int i=0; i<v.size(); i++) {
            ans += (push * v[i].first);
            keyId++;
            if(keyId==10) {
                push++;
                keyId = 2;
            }
        }
        return ans;
    }
};
