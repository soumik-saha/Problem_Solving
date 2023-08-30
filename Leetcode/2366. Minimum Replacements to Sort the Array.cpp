class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        for(int i=n-2; i>=0; i--) {
            if(nums[i]<=nums[i+1])
                continue;

            int num_elements;
            
            if(nums[i]%nums[i+1]==0) {
                num_elements = nums[i]/nums[i+1];
            }
            else {
                num_elements = nums[i]/nums[i+1] + 1;
            }
            
            ans += num_elements - 1;

            nums[i] = nums[i]/num_elements;
        }

        return ans;
    }
};
