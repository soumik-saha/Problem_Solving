//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    string multiplyStrings(string s1, string s2) {
       
        if(s1=="0" || s2=="0")
            return "0";
        
        vector<int> num(s1.size()+s2.size(), 0);
        
        int n1 = 0;
        int n2 = 0;
        
        if(s1[0] == '-')
            n1 = 1;
        if(s2[0] == '-')
            n2 = 1;
        if(s1[0] == '-' && s2[0] == '-')
            n1 = n2 = 1;
        
        for(int i=s1.size()-1; i>=n1; i--)
        {
            for(int j=s2.size()-1; j>=n2; j--)
            {
                num[i+j+1] += (s1[i]-'0') * (s2[j]-'0');
                num[i+j] += num[i+j+1]/10;
                num[i+j+1] = num[i+j+1]%10;
            }
        }

        int i=0;
        while(i<num.size() && num[i]==0)
            i++;
        
        string res = "";
        if(n1 ^ n2)
            res += '-';
        while(i < num.size())
            res.push_back(num[i++]+'0');
            
        return res;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends
