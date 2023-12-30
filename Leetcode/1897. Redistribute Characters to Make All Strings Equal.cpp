class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size()==1) 
            return true;
        unordered_map<char, int> freq;
        for(int i=0; i<words.size(); i++)
            for(char ch : words[i]) {
                freq[ch]++;
            }
        int changes = 0;
        int value = 0;
        for(auto it : freq) {
            if(it.second%words.size()!=0) {
                return false;
            }
        }
        return true;
    }
};
