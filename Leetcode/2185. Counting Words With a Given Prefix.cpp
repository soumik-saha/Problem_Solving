class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int count = 0;
        for(auto word:words) {
            if(word.size()<pref.size()) continue;
            count += (word.substr(0, pref.size())==pref) ? 1 : 0;
        }
        return count;
    }
};
