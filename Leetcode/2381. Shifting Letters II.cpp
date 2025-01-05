class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shifting(n, 0);
        for(auto& shift:shifts) {
            auto start = shift[0], end = shift[1], dir = shift[2];
            shifting[start] += (dir) ? 1 : -1;
            if(end+1<n) {
                shifting[end+1] -= (dir) ? 1 : -1;
            }
        }
        int numShifts = 0;
        for(int i=0; i<n; i++) {
            numShifts += shifting[i];
            int change = (s[i]-'a'+numShifts)%26;
            if(change<0)   change += 26;
            s[i] = 'a'+change;
        }
        return s;
    }
};
