class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n%3!=0)  return ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i=i+3) {
            vector<int> arr;
            arr.push_back(nums[i]);
            arr.push_back(nums[i+1]);
            arr.push_back(nums[i+2]);

            if(arr[1]-arr[0]>k) {
                ans.clear();
                return ans;
            }
            if(arr[2]-arr[0]>k) {
                ans.clear();
                return ans;
            }
            if(arr[2]-arr[1]>k) {
                ans.clear();
                return ans;
            }
            ans.push_back(arr);
        }

        return ans;
    }
};
