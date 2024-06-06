class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sum = 0;
        long long R0 = 0;
        
        for(int i=0; i<n; i++) {
            sum += a[i];
            R0 += static_cast<long long>(i)*a[i];
        }
        
        long long Ri = R0;
        long long res = R0;
        
        for(int i=0; i<n-1; i++) {
            long long Rip = Ri + sum - (static_cast<long long>(n)*a[n-1-i]);
            res = max(Rip, res);
            Ri = Rip;
        }
        
        return res;
    }
};
