//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int n, vector<int> color, vector<int> radius) {
        
        stack<pair<int,int> >st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                pair<int,int>p =make_pair(color[i],radius[i]);
                st.push(p);
            }
            else{
                pair<int,int>q=make_pair(color[i],radius[i]);
                if(st.top()==q){
                    st.pop();
                }
                else{
                    st.push(q);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends
