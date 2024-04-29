class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorTotal = 0;
        for (int num : nums) {
            xorTotal ^= num;
        }
        int xorDiff = xorTotal ^ k;
        int changes = countSetBits(xorDiff);
        return changes;
    }
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};
