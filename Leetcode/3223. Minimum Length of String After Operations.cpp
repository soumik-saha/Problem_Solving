class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        for(auto c:s) {
            freq[c]++;
        }
        int minLength = 0;
        for(auto &[key,val]:freq) {
            int temp = val;
            while(temp>2) {
                temp = (temp/3) + (temp%3);
            }
            minLength += temp;
        }
        return minLength;
    }
};
