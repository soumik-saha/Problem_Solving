class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0,j=s.size()-1;
        for(i=0; i<j; i++){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            j--;
        }
    }
};
