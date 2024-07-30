class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int cntB = 0;
        int curr = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                cntB++;
            } else {
                curr = min(curr + 1, cntB);
            }
        }

        return curr;
    }
};
