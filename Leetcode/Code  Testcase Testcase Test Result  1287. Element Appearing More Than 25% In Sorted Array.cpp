class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int i=0; i<arr.size(); i++) {
            freq[arr[i]]++;
            if(freq[arr[i]]>arr.size()/4) {
                return arr[i];
            }
        }
        return -1;
    }
};
