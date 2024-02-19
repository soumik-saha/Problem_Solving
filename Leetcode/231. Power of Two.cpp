class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)    return true;
        if(n<1)     return false;
        int last;
        while(n>=2) {
            if(n%2) return false;
            last = n;
            n /= 2;
        }
        return last==2;
    }
};
