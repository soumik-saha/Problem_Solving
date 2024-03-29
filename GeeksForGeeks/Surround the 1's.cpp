//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int totalcount = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count = 0;
                if(matrix[i][j]==1)
                {
                    //left
                    if(i>=0 && j-1>=0 && i<m && j<n)
                    {
                        if(matrix[i][j-1]==0)
                        {
                            count++;
                        }
                    }
                    //right
                    if(i>=0 && j>=0 && i<m && j+1<n)
                    {
                        if(matrix[i][j+1]==0)
                        {
                            count++;
                        }
                    }
                    //up
                    if(i-1>=0 && j>=0 && i<m && j<n)
                    {
                        if(matrix[i-1][j]==0)
                        {
                            count++;
                        }
                    }
                    //down
                    if(i>=0 && j>=0 && i+1<m && j<n)
                    {
                        if(matrix[i+1][j]==0)
                        {
                            count++;
                        }
                    }
                    //upper left diagonal
                    if(i-1>=0 && j-1>=0 && i<m && j<n)
                    {
                        if(matrix[i-1][j-1]==0)
                        {
                            count++;
                        }
                    }
                    //upper right diagonal
                    if(i-1>=0 && j>=0 && i<m && j+1<n)
                    {
                        if(matrix[i-1][j+1]==0)
                        {
                            count++;
                        }
                    }
                    //lower left diagonal
                    if(i>=0 && j-1>=0 && i+1<m && j<n)
                    {
                        if(matrix[i+1][j-1]==0)
                        {
                            count++;
                        }
                    }
                    //lower right digonal
                    if(i>=0 && j>=0 && i+1<m && j+1<n)
                    {
                        if(matrix[i+1][j+1]==0)
                        {
                            count++;
                        }
                    }
                }
                if(count!=0 && count%2==0)
                {
                    // cout<<i<<" "<<j<<" "<<count<<endl;
                    totalcount++;
                }
            }
        }
        return totalcount;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
