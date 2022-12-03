//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string s, string t, int M, int N) {
        int i,j,k,n=s.size(),count_A;
        char ch;
       vector<pair<char,int>>v1,v2; 
        for(i=0;i<n;i++)
        { 
            if(s[i]!='#')
            v1.push_back({s[i],i});
            if(t[i]!='#')
            v2.push_back({t[i],i});
          
        }
        if(v1.size()!=v2.size())
            return 0;
        for(i=0;i<v1.size();i++)
        {
            if(v1[i].first!=v2[i].first)
            return 0;
            
            else
            {
               if(v1[i].first=='A')            
               {
                   if(v1[i].second<v2[i].second)
                   return 0;
               }
               else
               {
                   if(v1[i].second>v2[i].second)
                   return 0;
               }
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends
