class Solution {
public:
    int pivotInteger(int n) {
        if(n==1)    return n;
        int prefixSum[n+1];
        prefixSum[0] = 0;
        for(int i=1; i<=n; i++) {
            prefixSum[i] = prefixSum[i-1] + i;
        }
        for(int i=n; i>=1; i--) {
            if(prefixSum[n]-prefixSum[i-1]==prefixSum[i-1]+i) {
                return i;
            }
        }
        return -1;
    }
};
