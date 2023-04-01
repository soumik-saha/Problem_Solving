class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int res = binarySearch(nums, target, l, r);
        return res;
    }

    int binarySearch(vector<int> nums, int target, int l, int r){
        if(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                return binarySearch(nums, target, l, mid-1);
            else
                return binarySearch(nums, target, mid+1, r);
        }
        return -1;
    }
};
