//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void helper(int i, int j, vector<vector<char>>& mat, int n, int m) {
        if(mat[i][j]!='O')
            return;
        
        mat[i][j] = '1';
        
        if(i>1) {
            helper(i-1, j, mat, n, m);
        }
        if(j>1) {
            helper(i, j-1, mat, n, m);
        }
        if(i+1<n) {
            helper(i+1, j, mat, n, m);
        }
        if(j+1<m) {
            helper(i, j+1, mat, n, m);
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0; i<n; i++) {
            helper(i, 0, mat, n, m);
            if(m>1)
                helper(i, m-1, mat, n, m);
        }
        
        for(int j=1; j+1<m; j++) {
            helper(0, j, mat, n, m);
            if(n>1)
                helper(n-1, j, mat, n, m);
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]=='O') {
                    mat[i][j] = 'X';
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]=='1') {
                    mat[i][j] = 'O';
                }
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
