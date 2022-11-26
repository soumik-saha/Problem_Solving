#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0; i<n; i++){
		int val;
		cin>>val;
		arr.push_back(val);
	}
	int x = count(arr.begin(), arr.end(), 1);
	if(x>0)	cout<<"HARD";
	else	cout<<"EASY";
	return 0;
}
