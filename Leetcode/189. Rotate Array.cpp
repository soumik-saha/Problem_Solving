class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()>1){
            if(k>nums.size())
                k = k%nums.size();
            vector<int> arr;
            for(int i=nums.size()-k; i<nums.size(); i++){
                arr.emplace_back(nums.at(i));
            }
            for(int i=nums.size()-k-1; i>=0; i--){
                nums[i+k] = nums[i];
            }
            for(int i=0; i<k; i++){
                nums[i] = arr[i];
            }
        }
    }
};
