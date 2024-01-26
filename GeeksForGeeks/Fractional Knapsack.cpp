//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, pair<double, double>>> ks;
        for(int i=0; i<n; i++) {
            double val = arr[i].value;
            double wei = arr[i].weight;
            ks.push_back({val/wei, {val, wei}});
        }
        sort(ks.rbegin(), ks.rend());
        int i=0;
        double ans = 0;
        while(W>0 && i<n) {
            if(W-ks[i].second.second>=0) {
                W -= ks[i].second.second;
                ans += ks[i].second.first;
            }
            else {
                ans += ks[i].first*W;
                W = 0;
            }
            i++;
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
