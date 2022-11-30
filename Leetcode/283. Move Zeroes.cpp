class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = count(nums.begin(), nums.end(), 0);
        remove(nums.begin(), nums.end(), 0);
        for(int i=0; i<cnt; i++)
            nums.pop_back();
        for(int i=0; i<cnt; i++)
            nums.emplace_back(0);
    }
};
