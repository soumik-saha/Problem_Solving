class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(char ch : chars) {
            mp[ch]++;
        }
        int count = 0;
        for(int i=0; i<words.size(); i++) {
            unordered_map<char, int> pm;
            for(char ch : words[i]) {
                pm[ch]++;
                
            }
            int cnt = 0;
            for(char ch : words[i]) {
                if(pm[ch]>mp[ch]) {
                    cnt = 0;
                    break;
                }
                cnt++;
            }
            count += cnt;
        }
        return count;
    }
};
