#include <iostream>
using namespace std;
int main() {
	int x = 0, n;
	cin>>n;
	string op[n];
	for(int i=0; i<n; i++){
		cin>>op[i];
		if(op[i][1]=='+')
			x++;
		else
			x--;
	}
	cout<<x;
	return 0;
}
