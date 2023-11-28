class Solution {
public:
    const int MOD = 1e9+7;
    int numberOfWays(string corridor) {
        long long n = corridor.size(), seatcount = 0, prev;
        long long ans = 1;

        for(int i=0; i<n; i++) {
            if(corridor[i]=='P') {
                continue;
            }
            seatcount++;

            if(seatcount>=3 && seatcount%2==1) {
                ans = (ans * (i-prev)) % MOD;
            }

            prev = i;
        }

        return (seatcount%2==1 || seatcount==0) ? 0 : ans;
    }
};
