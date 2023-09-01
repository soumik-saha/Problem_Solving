class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n+1, 0);
        for(int i=1; i<=n; i++) {
            arr[i] = setBits(i);
        }
        return arr;
    }
    int setBits(int x) {
        int count = 0;
        while(x!=0) {
            x = x & x-1;
            count++;
        }
        return count;
    } 
};
