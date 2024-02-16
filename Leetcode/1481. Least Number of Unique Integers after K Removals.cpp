class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }
        vector<int> freq;
        for(auto it: mp) {
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end());
        
        int eleRemoved = 0;

        for(int i=0; i<freq.size(); i++) {
            eleRemoved += freq[i];
            if(eleRemoved>k) {
                return freq.size()-i;
            }
        }

        return 0;
    }
};
