class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string word : words) {
            if(isPalindromic(word)) {
                return word;
            }
        }
        return "";
    }
    bool isPalindromic(string word) {
        int n = word.size();
        for(int i=0; i<n/2; i++) {
            if(word[i]!=word[n-1-i])
                return false;
        }
        return true;
    }
};
