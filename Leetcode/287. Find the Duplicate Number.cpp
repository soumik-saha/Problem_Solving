class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n, 0);

        for(int i=0; i<n; i++) {
            if(freq[nums[i]]==1)
                return nums[i];
            freq[nums[i]]++;
        }

        return -1;
    }
};
