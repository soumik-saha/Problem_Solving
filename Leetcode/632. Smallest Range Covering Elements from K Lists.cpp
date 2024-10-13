class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int low = 0, high = INT_MAX;
        vector<int> indices(k, 0);
        while(true) {
            int currMax = INT_MIN, currMin = INT_MAX, minListIndex = 0;

            for(int i=0; i<k; i++) {
                int ele = nums[i][indices[i]];

                if(ele<currMin) {
                    currMin = ele;
                    minListIndex = i;
                }

                if(ele>currMax) {
                    currMax = ele;
                }
            }

            if(currMax-currMin<high-low) {
                high = currMax;
                low = currMin;
            }

            if(++indices[minListIndex]==nums[minListIndex].size())  break;
        }
        return {low, high};
    }
};
