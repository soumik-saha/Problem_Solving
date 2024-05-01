class Solution {
public:
    string reversePrefix(string word, char ch) {
        int endIdx = word.find(ch);
        string result = word.substr(0, endIdx+1);
        reverse(result.begin(), result.end());
        result += word.substr(endIdx+1);
        return result;
    }
};
