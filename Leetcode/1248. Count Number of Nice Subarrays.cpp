class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int oddCount = 0;

        for(int left=0, right=0; right<n; right++) {
            if(nums[right]%2!=0) {
                oddCount++;
            }

            while(left<n && oddCount>k) {
                if(nums[left]%2!=0) {
                    oddCount--;
                }
                left++;
            }

            if(oddCount==k) {
                int firstOddIndex = left;
                while(nums[firstOddIndex]%2==0) {
                    firstOddIndex++;
                }
                ans += firstOddIndex - left + 1;
            }
        }

        return ans;
    }
};
