//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        bool negative = false, feasible = true;
        if(s[0]=='-')
            negative = true;
        
        if(negative) {
            for(int i=1; i<s.size(); i++) {
                if(s[i]>='0' && s[i]<='9') {
                    continue;
                }
                feasible = false;
                break;
            }
        } else {
            for(int i=0; i<s.size(); i++) {
                if(s[i]>='0' && s[i]<='9') {
                    continue;
                }
                feasible = false;
                break;
            }
        }
        
        if(!feasible)   return -1;
        
        int ans = 0;
        if(!negative) {
            for(int i=0; i<s.size(); i++) {
                ans = ans * 10 + s[i] - '0';
            }
        } else {
            for(int i=1; i<s.size(); i++) {
                ans = ans * 10 + s[i] - '0';
            }
            ans = -ans;
        }   
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
