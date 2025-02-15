class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;

        for(int i=1; i<=n; i++) {
            int squaren = i*i;
            if(canPartition(squaren, i)) {
                ans += squaren;
            }
        }

        return ans;
    }
    bool canPartition(int n, int target) {
        if(target<0 || n<target)    return false;
        if(n==target)   return true;
        return canPartition(n/10, target-n%10) || canPartition(n/100, target-n%100) || canPartition(n/1000, target-n%1000);
    }
};
