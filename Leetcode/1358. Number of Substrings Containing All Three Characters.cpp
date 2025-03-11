class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<int> alpha(3, 0);

        for(int l=0, r=0; r<n; r++) {
            alpha[s[r]-'a']++;
            while(l<=r && alpha[s[l]-'a']>1) {
                alpha[s[l++]-'a']--;
            }
            if(alpha[0]>0 && alpha[1]>0 && alpha[2]>0) {
                count += l+1;
            }
        }

        return count;
    }
};
