//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string>ans;
        for(auto str:Dictionary){
            int k=0;
            for(int i=0;i<str.length();i++){
                if(k==Pattern.size()){
                    ans.push_back(str);break;
                }
                if(str[i]>='A'&&str[i]<='Z'){
                    if(str[i]!=Pattern[k]){
                        break;
                    }
                    else k++;
                }
            }
        }
        if(ans.size()==0)return {"-1"};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
