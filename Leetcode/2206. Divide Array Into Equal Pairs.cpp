class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> count(501, 0);
        for(int num:nums)   count[num]++;
        for(int i=1; i<=500; i++)   if(count[i]%2==1)   return false;
        return true;
    } 
};
