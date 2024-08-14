class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(mid, nums) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
    int countPairs(int dist, vector<int>& nums) {
        int left = 0;
        int count = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (abs(nums[left] - nums[right]) > dist) {
                left++;
            }
            count += (right - left);
        }
        return count;
    }
};
