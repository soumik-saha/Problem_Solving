#include <bits/stdc++.h>
using namespace std;
int main() {
	int x1, x2, x3, mid, res;
	vector<int> a;
	cin>>x1>>x2>>x3;
	a.emplace_back(x1);
	a.emplace_back(x2);
	a.emplace_back(x3);
	sort(a.begin(), a.end());
	res = (a[1]-a[0])+(a[2]-a[1]);
	cout<<res;
	return 0;
}
