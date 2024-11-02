class Solution {
public:
    bool isCircularSentence(string sentence) {
        char last = sentence[0];
        for(int i=0; i<sentence.size(); i++) {
            if(sentence[i]!=last)   return false;
            while(i<sentence.size() && sentence[i]!=' ') {
                last = sentence[i];
                i++;
            }
        }
        return sentence.front()==sentence.back();
    }
};
