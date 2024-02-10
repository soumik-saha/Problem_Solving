class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=0; i<n; i++) {
            // odd length
            ans += solve(s, i, i);
            // even length
            ans += solve(s, i, i+1);
        }
        return ans;
    }
    int solve(string s, int low, int high) {
        int count = 0;

        while(low>=0 && high<s.size()) {
            if(s[low]!=s[high])
                break;
            count++;
            low--;
            high++;
        }
        
        return count;
    }
};
