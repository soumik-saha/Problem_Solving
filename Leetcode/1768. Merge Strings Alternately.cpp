class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int n = min(n1, n2);
        string word;
        int i;
        for(i=0; i<n; i++) {
            word.push_back(word1[i]);
            word.push_back(word2[i]);
        }
        while(i<n1){
            word.push_back(word1[i]);
            i++;
        }
        while(i<n2){
            word.push_back(word2[i]);
            i++;
        }
        return word;
    }
};
