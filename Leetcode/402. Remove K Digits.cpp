class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> stack;
        
        for(char digit : num) {
            while(!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                k -= 1;
            }
            stack.push_back(digit);
        }
        
        for(int i=0; i<k; ++i) {
            stack.pop_back();
        }
        
        string ret = "";
        bool leadingZero = true;
        for(char digit: stack) {
            if(leadingZero && digit == '0') continue;
            leadingZero = false;
            ret += digit;
        }
        
        if (ret.length() == 0) return "0";
        return ret;
    }
};
