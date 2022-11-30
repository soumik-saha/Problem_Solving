class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int res = int(columnTitle[0])-64;
        for(int i=1; i<n; i++){
            res = (res*26)+(int(columnTitle[i])-64);
        }
        return res;
    }
};
