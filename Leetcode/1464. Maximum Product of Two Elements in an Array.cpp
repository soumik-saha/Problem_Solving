class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x = INT_MIN, y = INT_MIN;

        for(int i=0; i<nums.size(); i++) {
            x = max(x, nums[i]);
        }

        int countX = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==x)
                countX++;
        }
        if(countX>1) {
            return (x-1)*(x-1);
        }
        else {
            for(int i=0; i<nums.size(); i++) {
                if(nums[i]<x) {
                    y = max(y, nums[i]);
                }
            }
        }

        return (x-1)*(y-1);
    }
};
