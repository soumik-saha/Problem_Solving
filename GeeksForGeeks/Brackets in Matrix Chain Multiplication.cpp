//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    vector<vector<pair<string, int>>> dp;
    string matrixChainOrder(int p[], int n){
        dp = vector<vector<pair<string, int>>>(n, vector<pair<string, int>>(n, {"", -1}));
        return solve(p, 1, n-1).first;
    }
    pair<string, int> solve(int p[], int i, int j) {
        if(i==j) {
            string s = "";
            s += 'A' + i - 1;
            return {s, 0};
        }
        
        if(dp[i][j].second!=-1) return dp[i][j];
        
        string sr = "";
        int m = 1e9;
        for(int k=i; k<j; k++) {
            auto l = solve(p, i, k);
            auto r = solve(p, k+1, j);
            
            int x = p[i-1]*p[k]*p[j] + l.second + r.second;
            
            string s = "("+l.first+r.first+")";
            
            if(m>x) {
                m = x;
                sr = s;
            }
        }
        
        return dp[i][j] = {sr, m};
    }
};

//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
