class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        int index=-1;

        while(left<=right) {
            int mid = left + (right-left) / 2;
            
            if(nums[mid]==target) {
                index = mid;
                while(index>=0 && nums[index]==target) {
                    index--;
                }
                left = index+1;
                index = mid;
                while(index<=nums.size()-1 && nums[index]==target) {
                    index++;
                }
                right = index-1;
                break;  
            }
            else if(nums[mid]>target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        vector<int> ans;
        if(index==-1) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else {            
            ans.push_back(left);
            ans.push_back(right);
        }

        return ans;
    }
};
