class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c:s) {
            mp[c]++;
        }
        vector<pair<char, int>> freqMap(mp.begin(), mp.end());
        sort(freqMap.begin(), freqMap.end(), compare);
        string ans;
        for(auto it:freqMap) {
            while(it.second--)
                ans.push_back(it.first);
        }
        return ans;
    }
    static bool compare(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    }
};
