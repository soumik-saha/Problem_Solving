class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n<k) return false;

        unordered_map<char, int> mp;
        for(auto c:s) {
            mp[c]++;
        } 

        int oddCount = 0;
        for(auto [key,v]:mp) {
            oddCount += (v%2==1);
        }

        return oddCount<=k;
    }
};
