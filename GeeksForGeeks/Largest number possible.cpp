//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S)
    {
        string str;
        int digits=0;
        int val=S;
        if(S==0 && N>1)
        {
            return "-1";
        }
        if(S==0 && N==1)
        {
            return "0";
        }
        while(val>0)
        {
            if(val>=9)
            {
                val=val-9;
                str=str+"9";
                digits++;
            }
            else if(val<9)
            {
                char a=char(val+48);
                str=str+a;
                digits++;
                break;
            }
        }
        if(digits>N)
        {
            return "-1";
        }
        else 
        {
            for(int i=digits+1;i<=N;i++)
            {
                str=str+"0";
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
