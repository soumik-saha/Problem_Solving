class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.size() < 10) return result;
        unordered_map<int, int> v;
        unordered_map<char, int> m{{'A', 0}, {'C', 1}, {'G',2}, {'T', 3}};
        int t =0;
        for (int i=0; i <= s.size()-10; ++i) {
            if (i == 0) for (int j=0; j < 10; ++j )  t = (t << 2) | (m[s[j]] & 0x3);
            else t = ((t << 2) | (m[s[i+9]] & 0x3)) & (0xfffff);   
            if (v[t]++ == 1) result.push_back(s.substr(i, 10));
        }
        return result;
    }
};
