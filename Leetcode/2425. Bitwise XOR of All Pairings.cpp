class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, long long> freq;
        for(auto num:nums1) {
            freq[num]+=n2;
        }
        for(auto num:nums2) {
            freq[num]+=n1;
        }
        int ans = 0;
        for(auto& [num, count]:freq) {
            if(count%2==1) {
                ans ^= num;
            }
        }
        return ans;
    }
};
