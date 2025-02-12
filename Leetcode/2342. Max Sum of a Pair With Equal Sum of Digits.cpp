class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, priority_queue<int>> mp;

        for(int num:nums) {
            int digSum = digitSum(num);
            mp[digSum].push(num);
        }

        int ans = -1;
        for(auto it:mp) {
            if(it.second.size()>=2) {
                int currSum = 0;
                currSum = it.second.top();
                it.second.pop();
                currSum += it.second.top();
                it.second.pop();
                ans = max(ans, currSum);
            }
        }

        return ans;
    }
    int digitSum(int num) {
        int sum = 0;
        while(num>0) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
};
