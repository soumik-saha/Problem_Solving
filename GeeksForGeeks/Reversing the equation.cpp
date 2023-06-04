//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
         vector<string>a;
         string sym="";
         int n=s.length();
         string tmp="";
         for(int i=0;i<n;i++){
             if(s[i]>='0'&&s[i]<='9')tmp+=s[i];
             else {
                 a.push_back(tmp);
                 tmp="";
                 sym+=s[i];}
         }
         
         a.push_back(tmp);
         reverse(a.begin(),a.end());
         reverse(sym.begin(),sym.end());
         
         string ans="";
         ans+=a[0];
         for(int i=1;i<a.size();i++){
             ans+=sym[i-1];
             ans+=a[i];
         }
         return ans;
        }
};
//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
