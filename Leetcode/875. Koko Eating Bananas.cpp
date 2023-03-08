class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1000000000;
        while(left<right) {
            int mid = (left + right) / 2, total = 0;
            for (int p:piles) {
                total += (p + mid - 1) / mid;
            }
            if (total > h) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};
