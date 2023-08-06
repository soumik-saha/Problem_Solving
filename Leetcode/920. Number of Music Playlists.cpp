#include <vector>

class Solution {
private:
    static const long long MOD = 1e9 + 7;
    vector<long long> factorial;
    vector<long long> invFactorial;

    long long power(long long base, int exponent) {
        long long result = 1;
        while (exponent > 0) {
            if (exponent & 1) {
                result = (result * base) % MOD;
            }
            exponent >>= 1;
            base = (base * base) % MOD;
        }
        return result;
    }

    void precalculateFactorials(int n) {
        factorial.resize(n + 1);
        invFactorial.resize(n + 1);
        factorial[0] = invFactorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
            invFactorial[i] = power(factorial[i], MOD - 2);
        }
    }

public:
    int numMusicPlaylists(int n, int goal, int k) {
        precalculateFactorials(n);
        int sign = 1;
        long long answer = 0;
        for (int i = n; i >= k; i--) {
            long long temp = power(i - k, goal - k);
            temp = (temp * invFactorial[n - i]) % MOD;
            temp = (temp * invFactorial[i - k]) % MOD;
            answer = (answer + sign * temp + MOD) % MOD;
            sign *= -1;
        }
        return (factorial[n] * answer) % MOD;
    }
};
