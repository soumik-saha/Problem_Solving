class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxPile = *max_element(candies.begin(), candies.end());
        
        int left = 0;
        int right = maxPile;

        while(left<right) {
            int mid = (left + right + 1) / 2;
            if(canAllocate(candies, k, mid)) {
                left = mid;
            }
            else {
                right = mid-1;
            }
        }

        return left;
    }
    bool canAllocate(vector<int>& candies, long long k, int n) {
        long long maxCandies = 0;

        for(int i=0; i<candies.size(); i++) {
            maxCandies += candies[i] / n;
        }

        return maxCandies>=k;
    }
};
