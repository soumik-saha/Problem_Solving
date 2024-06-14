class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int maxEle = INT_MIN;
        
        for (int num : nums) {
            maxEle = max(maxEle, num);
        }

        vector<int> mp(maxEle + n, 0);

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int moves = 0;
        int curr = 0;

        for (int i = 0; i < mp.size(); i++) {
            if (mp[i] > 1) {
                curr += mp[i] - 1;
            } else if (curr > 0 && mp[i] == 0) {
                curr--;
            }
            moves += curr;
        }

        return moves;
    }
};
