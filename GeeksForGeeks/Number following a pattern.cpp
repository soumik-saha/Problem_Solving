//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans;
        int n = S.size();
        
        for(int j=0; j<n+1; j++) {
            ans += to_string(j+1);
        }
        
        for(int i=0; i<n; i++) {
            if(S[i]=='I') 
                continue;
            
            int cnt = 1;
            int k = i;
            while(i<n && S[i]=='D') {
                cnt++;
                i++;
            }
            
            reverse(ans.begin()+k, ans.begin()+k+cnt);
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
