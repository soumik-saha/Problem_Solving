class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorCnt = start^goal;
        return __builtin_popcount(xorCnt);
    }
};
