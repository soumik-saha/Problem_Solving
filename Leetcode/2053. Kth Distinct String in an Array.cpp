class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        for(string s:arr) {
            freq[s]++;
        }
        vector<string> distinct;
        for(string s:arr) {
            if(freq[s]==1) {
                distinct.push_back(s);
            }
        }

        return (k<=distinct.size()) ? distinct[k-1] : "";
    }
};
