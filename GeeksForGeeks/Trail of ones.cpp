class Solution {
  public:
    const int MOD = 1e9+7;
    int numberOfConsecutiveOnes(int n) {
        // code here
        long long prev1 = 0, prev2 = 0;
        long long x = 0;
        
        for(int i=2; i<=n; i++) {
            x = (static_cast<long long>(Pow(2, i-2)) + prev1 + prev2) % MOD;
            prev2 = prev1;
            prev1 = x;
        }
        
        return x;
    }
    long long Pow(int n, int m) {
        if(m==0) {
            return 1;
        }
        
        long long half = Pow(n, m/2) % MOD;
        if(m%2==1) {
            return half * half * n;
        }
        return half * half;
    }
};
