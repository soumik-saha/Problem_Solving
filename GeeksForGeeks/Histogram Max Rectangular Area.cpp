//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        vector<int> nxtSmall = nextSmaller(arr);
        vector<int> preSmall = prevSmaller(arr);
        
        int ans = 0;
        
        for(int i=0; i<arr.size(); i++) {
            int len = arr[i];
            if(nxtSmall[i]==-1)     nxtSmall[i] = arr.size();
            int breadth = nxtSmall[i]-preSmall[i]-1;
            ans = max(ans, len*breadth);
        }
        
        return ans;
    }
    vector<int> prevSmaller(vector<int>& arr) {
        stack<int> stk;
        vector<int> v;
        
        for(int i=0; i<arr.size(); i++) {
            while(!stk.empty() && arr[stk.top()]>=arr[i]) {
                stk.pop();
            }
            stk.empty() ? v.push_back(-1) : v.push_back(stk.top());
            stk.push(i);
        }
        
        return v;
    }
    vector<int> nextSmaller(vector<int>&arr){
      stack<int>st;
      vector<int>vec(arr.size());
      for(int i=arr.size()-1;i>=0;i--){
          while(st.empty()==false && arr[st.top()]>=arr[i])
          st.pop();
          st.empty()?vec[i]=-1:vec[i]=st.top();
          st.push(i);
      }
      return vec;
  }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
