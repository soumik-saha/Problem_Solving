class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for(auto it : nums){
            if(hashset.count(it)>0){
                return true;
            }
            hashset.insert(it);
        }
        return false;
    }
};
