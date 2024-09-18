//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        if(x.size()%2==1 || x[0]==')' || x[0]=='}' || x[0]==']') {
            return false;
        }
        
        stack<char> stk;
        for(int i=0; i<x.size(); i++) {
            if(x[i]=='(' || x[i]=='{' || x[i]=='[') {
                stk.push(x[i]);
            }
            else {
                if((!stk.empty() && ((x[i]==')' && stk.top()!='(') || (x[i]=='}' && stk.top()!='{') || (x[i]==']' && stk.top()!='['))) || (stk.empty() && ((x[i]==')') || (x[i]=='}') || (x[i]==']')))) {
                    return false;
                }
                else {
                    if(!stk.empty())
                        stk.pop();
                }
            }
        }
        
        return stk.size()==0;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
