class Solution {
public:
    string compressedString(string word) {
        string comp;
        int n = word.size();
        int i = 0;
        while(i<n) {
            int count = 1;
            char c = word[i];

            while(i+1<n && word[i+1]==c && count<9) {
                i++;
                count++;
            }

            comp += to_string(count);
            comp.push_back(c);
            i++;
        }
        return comp;
    }
};
