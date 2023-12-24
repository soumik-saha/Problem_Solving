//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.first<b.first)
        return 1;
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        else
        return 0;
    }
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        v.push_back({price[i],i+1});
        
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        for(auto it:v)
        {
            int p=it.first;
            int num=it.second;
            
            int xx=k/p;
            if(xx>num)
            {
                ans+=num;
                k-=(num*p);
            }
            else
            {
                ans+=xx;
                k-=(xx*p);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
