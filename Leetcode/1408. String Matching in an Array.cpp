class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        unordered_set<string> seen;
        for(auto word:words) {
            for(auto it:words) {
                if(it==word)    continue;
                if(it.find(word)!=string::npos) {
                    if(seen.find(word)==seen.end()) {
                        ans.push_back(word);
                        seen.insert(word);
                    }
                }
            }
        }
        return ans;
    }
};
