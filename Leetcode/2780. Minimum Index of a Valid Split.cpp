class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        unordered_set<int> x;

        for(int num:nums) {
            freq[num]++;
            if(freq[num]>=n/2)  x.insert(num);
        }

        unordered_map<int, int> f2;
        for(int i=0; i<n; i++) {
            f2[nums[i]]++;
            if(i!=n-1 && x.find(nums[i])!=x.end() && freq[nums[i]]-f2[nums[i]]>(n-i-1)/2 && f2[nums[i]]>(i+1)/2) {
                return i;
            }
        }

        return -1;
    }
};
