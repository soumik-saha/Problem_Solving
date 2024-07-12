class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int gain = 0;
        string highPriority = x>y ? "ab" : "ba";
        string lowPriority = highPriority=="ab" ? "ba" : "ab";

        string firstPass = removeSubstring(s, highPriority);
        int removedPairsCnt = (s.size()-firstPass.size())/2;

        gain += removedPairsCnt * max(x, y);

        string secondPass = removeSubstring(firstPass, lowPriority);
        removedPairsCnt = (firstPass.size()-secondPass.size())/2;

        gain += removedPairsCnt * min(x,y);

        return gain;
    }
    string removeSubstring(string& s, string& target) {
        stack<char> stk;

        for(char c:s) {
            if(c==target[1] && !stk.empty() && stk.top()==target[0]) {
                stk.pop();
            }
            else {
                stk.push(c);
            }
        }

        string rem;
        while(!stk.empty()) {
            rem += stk.top();
            stk.pop();
        }

        reverse(rem.begin(), rem.end());

        return rem;
    }
};
