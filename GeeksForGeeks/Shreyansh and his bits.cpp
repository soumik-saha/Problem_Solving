//User function Template for C++

class Solution{
public:
    
    long long nck(long long n, long long k){
        if(n == 0 || n < k) return 0;
        long long res = 1;
        if (k > n - k)
            k = n - k;
        for (int i = 0; i < k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        
        return res;
    }
    long long count(long long x) {
        long long r = 0;
        int number_of_set_bits = 0;
        for(int i = 0; i < 64;++i){
            if(x & 1){
                number_of_set_bits++;
                long long nck_r = nck(i,number_of_set_bits);
                r += nck_r;
            }
            x = x >> 1;
        }
        return r;
    }
};
