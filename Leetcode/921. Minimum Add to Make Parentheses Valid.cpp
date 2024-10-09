class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int minAdd = 0;
        for(char c:s) {
            if(c==')') {
                if(open>0) {
                    open--;

                }
                else {
                    minAdd++;
                }
            }
            else {
                open++;
            }
        }
        return open+minAdd;;
    }
};
