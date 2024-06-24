class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> flipped(n, false);
        int prevValidFlips = 0;
        int flipCount = 0;

        for(int i=0; i<n; i++) {
            if(i>=k) {
                if(flipped[i-k]) {
                    prevValidFlips--;
                }
            }

            if(prevValidFlips%2==nums[i]) {
                if(i+k>n) {
                    return -1;
                }
                prevValidFlips++;
                flipped[i] = true;
                flipCount++;
            }
        }

        return flipCount;
    }
};
