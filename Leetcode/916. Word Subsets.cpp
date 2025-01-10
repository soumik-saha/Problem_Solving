class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int m = words1.size(), n = words2.size();
        vector<string> ans;
        vector<int> alpha(26,0);
        for(auto word:words2) {
            vector<int> alp(26, 0);
            for(auto w:word) {
                alp[w-'a']++;
            }
            for(int i=0; i<26; i++) {
                alpha[i] = max(alpha[i], alp[i]);
            }
        }
        for(auto word:words1) {
            bool isUniversal = true;
            unordered_map<char, int> mp;
            for(auto w:word) {
                mp[w]++;
            }
            for(auto i=0; i<26; i++) {
                mp['a'+i]-=alpha[i];
                if(mp['a'+i]<0) {
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal) ans.push_back(word);
        }
        return ans;
    }
};
