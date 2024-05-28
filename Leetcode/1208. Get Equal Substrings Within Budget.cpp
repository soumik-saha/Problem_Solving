class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        
        int maxLen = 0;
        int currCost = 0;
        for(int left=0, right=0; right<n; right++) {
            currCost += abs((int)s[right]-(int)t[right]);
            
            while(left<n && maxCost<currCost) {
                currCost -= abs((int)s[left]-(int)t[left]);
                left++;
            }

            maxLen = max(maxLen, right-left+1);
        }

        return maxLen;
    }
};
