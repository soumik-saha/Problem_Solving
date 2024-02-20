#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n;
    cin>>n;
    ll a[n-1];

    for(ll i=0; i<n-1; i++) 
        cin>>a[i];

    unordered_map<ll, ll> mp;
    for(ll i=0; i<n-1; i++) {
        mp[a[i]]++;
    }

    for(ll i=1; i<=n; i++) {
        if(mp[i]==0) {
            cout<<i;
            break;
        }
    }

    return 0;
}
