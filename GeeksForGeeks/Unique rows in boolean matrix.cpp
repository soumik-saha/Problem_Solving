//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        vector<vector<int>>ans;
        vector<int>v;
        map<vector<int>,int>mp;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                
                v.push_back(M[i][j]);
            }
            if(mp[v]==0){
            mp[v]++;
            ans.push_back(v);
            }
            v.clear();
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends
