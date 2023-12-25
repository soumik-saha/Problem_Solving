// Link: https://www.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1

// Intuition:
// Basically, we need to use recursion; in the base case, n==1 or n==2 then we can just know How to solve it by solving a simple determinant.
// But more than n==2, we have to find the submatrix, then we can minimize it and solve it by calling the function.
// Add all the sums and return it as answer. Sign must be changed every time of addition.

// Code
class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here 
        if(n==1) {
            return matrix[0][0];
        }
        if(n==2) {
            return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
        }
        
        int det = 0;
        for(int i=0, sign=1; i<n; i++, sign=sign*-1) {
            vector<vector<int>> subMatrix;
            for(int j=1; j<n; j++) {
                vector<int> row;
                for(int k=0; k<n; k++) {
                    if(k==i)    continue;
                    row.push_back(matrix[j][k]);
                }
                subMatrix.push_back(row);
            }
            int subMatrixDet = determinantOfMatrix(subMatrix, n-1);
            
            det += subMatrixDet*sign*matrix[0][i];
        }
        return det;
    }
};
