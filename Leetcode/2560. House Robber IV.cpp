class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int minReward = 1, maxReward = *max_element(nums.begin(), nums.end()), ans = 0;

        while(minReward<maxReward) {
            int mid = minReward + (maxReward-minReward)/2;
            int possibleThefts = 0;

            for(int i=0; i<n; i++) {
                if(nums[i]<=mid) {
                    possibleThefts++;
                    i++;
                }
            }

            if(possibleThefts>=k)   maxReward = mid;
            else    minReward = mid+1;
        }

        return minReward;
    }
};
