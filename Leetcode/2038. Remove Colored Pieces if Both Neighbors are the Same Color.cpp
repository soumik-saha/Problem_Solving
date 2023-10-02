class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.size()<3) return false;

        int countA=0, countB=0;
        int n = colors.size();

        for(int i=1; i<n-1; i++) {
            if(colors[i]=='A') {
                if(colors[i-1]=='A' && colors[i+1]=='A') {
                    countA++;
                }
            }
            else if(colors[i]=='B') {
                if(colors[i-1]=='B' && colors[i+1]=='B') {
                    countB++;
                }
            }
        }

        if(countA>countB) {
            return true;
        }
        else {
            return false;
        }
    }
};
