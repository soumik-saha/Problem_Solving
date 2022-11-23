#include <bits/stdc++.h>
using namespace std;
int min(int x, int y, int z){
	if(x<y){
		if(x<z)
			return x;
		else
			return z;
	}
	else{
		if(y<z)
			return y;
		else
			return z;
	}
}
int main() {
	int n, k, l, c, d, p, nl, np;
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	cout<<(int)(min(((l*k)/nl),(c*d),(p/np))/n);
	return 0;
}
