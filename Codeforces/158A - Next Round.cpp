#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
        ll n,k,cnt=0;
        cin>>n>>k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            
        }
        k = arr[k-1];
        while (n--)
        {
            if(arr[n]>=k && arr[n]>0)
                cnt++;
        }
        cout<<cnt<<endl;
    return 0;
}
