//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int m =  matrix.size(), n = matrix[0].size();
        vector<int> ans;
        int totalEle = m*n;
        int eleCnt = 0;
        for(int i=0; i<=min(m/2,n/2); i++) {
            for(int j=i; j<n-i && eleCnt!=totalEle; j++) {
                ans.push_back(matrix[i][j]);
                eleCnt++;
            }
            for(int k=i+1; k<m-i && eleCnt!=totalEle; k++) {
                ans.push_back(matrix[k][n-1-i]);
                eleCnt++;
            }
            for(int l=n-2-i; l>=i && eleCnt!=totalEle; l--) {
                ans.push_back(matrix[m-1-i][l]);
                eleCnt++;
            }
            for(int p=m-2-i; p>=i+1 && eleCnt!=totalEle; p--) {
                ans.push_back(matrix[p][i]);
                eleCnt++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
