class Solution {
public:
    int getBigger(vector<int>&nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans =  -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) low = mid + 1;
            else 
            {
                ans = nums[mid];
                high = mid - 1;
            }
        }
        return ans;
    }
    int solve(vector<int>&nums1, vector<int>& nums2, map<pair<int, int>, int>&mp, int currIdx, int prev)
    {
        if (currIdx == nums1.size()) return 0;
        if (mp.count({currIdx, prev})) return mp[{currIdx, prev}];
        
        int x = INT_MAX, y = INT_MAX, z = INT_MAX;
        int newCurr = nums1[currIdx], curr = nums1[currIdx];
        if (nums1[currIdx] <= prev)  
        {
            newCurr = getBigger(nums2, prev);
            if (newCurr > prev) 
                x = solve(nums1, nums2, mp, currIdx + 1, newCurr);
            if (x != INT_MAX) x++; 
        }
        else  
        {
            y = solve(nums1, nums2, mp, currIdx + 1, curr);  
            newCurr = getBigger(nums2, prev); 
            if (newCurr > prev) 
                z =  solve(nums1, nums2, mp, currIdx + 1, newCurr); 
            if (z != INT_MAX) z++; 
        }
        return mp[{currIdx, prev}] = min({x, y, z});
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) 
    {
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, int>mp;
        int ans = solve(arr1, arr2,mp,  0, -1);
        return (ans == INT_MAX? -1 : ans);
    }
};
