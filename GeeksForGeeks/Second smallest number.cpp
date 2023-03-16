//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int s, int d){
        // code here 
        if(s==1 || d==1 || 9*d <= s)return "-1";
        string res="";
        while(res.size()!=d){
            if(s>=9){
                s-=9;
                res+="9";
            }else{
                res=to_string(s)+res;
                s-=s;
            }
        }
    
        if(res[0]=='0'){
            res[0]='1';
            for(int i=1;i<d;i++){
                if(res[i]!='0'){
                    res[i]=res[i]-1;
                    break;
                }
            }
        }

        if(res[d-1]!='9'){
            res[d-1]=res[d-1]-1;
            res[d-2]=res[d-2]+1;
        }else{
            for(int i=d-2;i>=0;i--){
                if(res[i]!='9'){
                    res[i]=res[i]+1;
                    res[i+1]=res[i+1]-1;
                    break;
                }
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
