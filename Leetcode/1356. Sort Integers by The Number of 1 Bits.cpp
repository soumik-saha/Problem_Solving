class Solution {
public:
    static bool compareOnes(int i1, int i2) {
        if(__builtin_popcountll(i1) == __builtin_popcountll(i2)) {
            return i1 < i2;
        }
        return __builtin_popcountll(i1) < __builtin_popcountll(i2);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compareOnes);
        return arr;
    }
};
