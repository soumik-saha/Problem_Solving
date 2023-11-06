//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int calc(int i, int j,int n, int m, vector<vector<int>> &mat, int k){
          int sum=0;
          for(int l=i-k;l<=i+k;l++){if(j>=k and l>=0 and l<n)sum+=mat[l][j-k];}
          for(int l=i-k;l<=i+k;l++){if(j+k<m and l>=0 and l<n)sum+=mat[l][j+k];}
          for(int l=j-k+1;l<=j+k-1;l++){if(i>=k and l>=0 and l<m)sum+=mat[i-k][l];}
          for(int l=j-k+1;l<=j+k-1;l++){if(i+k<n and l>=0 and l<m)sum+=mat[i+k][l];}
        return sum;
   }
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> qr[])
    {
        vector<int>ans(q);
        for(int i=0;i<q;i++){
            ans[i]=calc(qr[i][1], qr[i][2],n, m, mat, qr[i][0]);
        }
        return ans;
    }
};
 



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends
