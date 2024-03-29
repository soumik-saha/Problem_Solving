//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        int n=S.length();
        int MinInd=0,MaxLen=1;
        for(int center=0;center<n;center++)
        {
            int i=center,j=center;
            while(i>=0 && j<n && S[i]==S[j])
            {
                i--;
                j++;
            }
            i++;
            j--;
            if(j-i+1>MaxLen)
            {
                MaxLen=j-i+1;
                MinInd=i;
            }
            else if(j-i+1==MaxLen)
            {
                MinInd=min(MinInd,i);
            }
    
            i=center,j=center+1;
            while(i>=0 && j<n && S[i]==S[j])
            {
                i--;
                j++;
            }
            i++;
            j--;
            if(j-i+1>MaxLen)
            {
                MaxLen=j-i+1;
                MinInd=i;
            }
            else if(j-i+1==MaxLen)
            {
                MinInd=min(MinInd,i);
            }
        }
        return S.substr(MinInd,MaxLen);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
