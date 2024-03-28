class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int result = 0;

        for(int left=0, right=0; right<n; right++) {
            freq[nums[right]]++;

            while(freq[nums[right]]>k) {
                freq[nums[left++]]--;
            }

            result = max(result, right-left+1);
        }

        return result;
    }
};
