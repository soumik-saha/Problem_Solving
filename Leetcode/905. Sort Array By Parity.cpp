class Solution {
private:
    static bool compare(int a, int b) {
        return (a%2==0 && b%2!=0);
    }
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        return nums;
    }
};
