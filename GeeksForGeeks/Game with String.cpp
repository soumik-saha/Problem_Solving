//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }
        priority_queue<int> pq;
        for(auto it:mp) {
            pq.push(it.second);
        }
        while(k--) {
            int x = pq.top()-1;
            pq.pop();
            pq.push(x);
        }
        int ans = 0;
        while(!pq.empty()) {
            ans += pq.top()*pq.top();
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
