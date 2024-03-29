class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = INT_MIN;
        for(int num:nums) {
            maxElement = max(maxElement, num);
        }

        long long n = nums.size();
        long long countMax = 0;
        long long res = 0;

        for(long long left=0, right=0; right<n; right++) {
            if(nums[right] == maxElement) {
                countMax++;
            }
            
            while(countMax>=k) {
                if(left<=right && nums[left]==maxElement) {
                    if(countMax==k) {
                        break;
                    }
                    countMax--;
                }
                left++;
            }

            if(countMax==k) {
                res += left+1;
            }
        } 

        return res;
    }
};
