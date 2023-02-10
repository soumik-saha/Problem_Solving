//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int a[5]={0};
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='b')
                a[0]++;
            if(s[i]=='a')
                a[1]++;
            if(s[i]=='l')
                a[2]++;
            if(s[i]=='o')
                a[3]++;
            if(s[i]=='n')
                a[4]++;
        }
            a[2]=a[2]/2;
            a[3]=a[3]/2;
            int ans=INT_MAX;
            for(int i=0;i<5;i++)
                if(a[i]<ans)
                    ans=a[i];
            return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
