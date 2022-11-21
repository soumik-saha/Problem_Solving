#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int rows = 5, cols = 5, rc, rr;
	int mat[rows][cols];
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cin>>mat[i][j];
			if(mat[i][j]==1){
				rc = j;
				rr = i;
			}
		}
	}
	int ans = abs((2-rr))+abs((2-rc));
	cout<<ans;
	return 0;
}
