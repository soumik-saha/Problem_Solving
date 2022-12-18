// User function Template for C++

#define ll long long int
class Solution {
  public:
    ll solve(ll n) {
        ll a1 = n;
        int include=0;
        for(ll i=n-1;i>=1;i--) {
            ll g = gcd(a1,i);
            if(g==1) {
                a1*=i;
                include++;
            }
            if(include==3) return a1;
        }
        return a1;
    }
    
    long long maxGcd(int N) {
        return max(solve(N),solve(N-1));
    }
    
    ll gcd(ll a,ll b) {
        if(a==0) return b;
        return gcd(b%a,a);
    }
};
