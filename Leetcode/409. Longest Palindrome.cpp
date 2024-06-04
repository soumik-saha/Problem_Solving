class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> mp;
        for(char c:s) {
            mp[c]++;
        }
        int maxLen = 0;
        int oddLen = 0;
        for(auto it:mp) {
            if(it.second%2==0) {
                maxLen += it.second;
            }
            else {
                maxLen += it.second - 1;
                oddLen++;
            }
        }

        return oddLen ? maxLen + 1 : maxLen;
    }
};
