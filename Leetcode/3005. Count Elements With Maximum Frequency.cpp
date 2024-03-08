class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxfreq = 0;
        for(int num:nums) {
            mp[num]++;
            maxfreq = max(maxfreq, mp[num]);
        }
        int count = 0;
        for(auto it:mp) {
            if(it.second==maxfreq) {
                count++;
            }
        }
        return count * maxfreq;
    }
};
