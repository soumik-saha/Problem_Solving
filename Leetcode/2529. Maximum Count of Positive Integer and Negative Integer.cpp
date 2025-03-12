class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int posLeft = -1, negRight = -1;
        int left=0, right=n-1;

        while(left<=right) {
            int mid = left + (right-left) / 2;
            if(nums[mid]<0) {
                negRight = mid;
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }

        left = 0, right = n-1;
        while(left<=right) {
            int mid = left + (right-left) / 2;
            if(nums[mid]>0) {
                posLeft = mid;
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }

        if(negRight==-1 && posLeft==-1)   return 0;
        if(negRight==-1)    return n-posLeft;
        if(posLeft==-1)     return negRight+1;

        return max(negRight+1, n-posLeft);
    }
};
