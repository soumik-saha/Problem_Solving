//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<pair<int, int>, int>> time;
        for(int i=0; i<N; i++) {
            time.push_back(make_pair(make_pair(S[i], F[i]), i+1));
        }
        sort(time.begin(), time.end(), compare);
        vector<int> res;
        res.push_back(time[0].second);
        int prev = time[0].first.second;
        for(int i=1; i<time.size(); i++) {
            if(time[i].first.first>prev) {
                res.push_back(time[i].second);
                prev = time[i].first.second;
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
    static bool compare (pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        if(a.first.second==b.first.second) {
            return a.second < b.second;
        }
        return a.first.second < b.first.second;
    }
    // T.C. -> O(N logN)
    // S.C. -> O(N)
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
