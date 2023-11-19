class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0, cnt = 0;
        int i=1; 
        while(i<nums.size()) {
            if(nums[i-1]!=nums[i]) {
                cnt++;
            }
            ans += cnt;
            i++;
        }

        return ans;
    }
};

// T.C. -> O(N LOG N)
// S.C. -> O(1)
