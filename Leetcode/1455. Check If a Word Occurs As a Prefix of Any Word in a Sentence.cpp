class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int idx = 1;
        for(int i=0; i<sentence.size(); i++) {
            string word;
            while(i<sentence.size() && sentence[i]!=' ') {
                word.push_back(sentence[i++]);
            }
            if(word.size()>=searchWord.size() && word.substr(0,searchWord.size())==searchWord) {
                return idx;
            }
            idx++;
        }
        return -1;
    }
};
