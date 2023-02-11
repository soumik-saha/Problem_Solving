//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int N,string s, vector<int> &P) {
        //to store last day when inserting '?' is helpful means duplicates are there at pos -1 and pos + 1 positions
        int cnt = 0;
        int n = P.size();
        
        for(int i = 0; i < n; i++)
        {
            int pos = P[i];
            if((pos > 0 && s[pos - 1] == s[pos]) || (pos < n-1 && s[pos + 1] == s[pos]) && s[pos] != '?')
            {
                cnt = i + 1;
                s[pos] = '?';
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
