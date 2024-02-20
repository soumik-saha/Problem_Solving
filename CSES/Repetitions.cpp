#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin>>s;
    if(s.size()<=1) {
        cout<<s.size();
        return 0;
    }
    ll count= 0;
    ll left = 0; 
    ll right = 1;

    while(left<s.size() && right<s.size()){
        while(s[left]==s[right]) {
            count = max(count, right-left+1);
            right++;
        }
        left = right;
    }
    cout<<count<<endl;

    return 0;
}
