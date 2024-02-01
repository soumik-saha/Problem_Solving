//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        vector<int> alpha(26, 0);
        
        for(char ch : s) {
            if(ch>='a' && ch<='z')
                alpha[ch-'a'] = 1;
            else if(ch>='A' && ch<='Z')
                alpha[ch-'A'] = 1;
        }
        
        int sum = accumulate(alpha.begin(), alpha.end(), 0);
        
        return sum == 26;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends
