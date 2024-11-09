//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        string x, y;
        for(int i=0; i<n; i+=1) {
            if(i%2==0)
                x.push_back(arr[i]+'0');
            else
                y.push_back(arr[i]+'0');
        }
        string ans;
        int i = x.size()-1;
        int j = y.size()-1;
        int carry = 0;
        while(i>=0 || j>=0 || carry) {
            int sum = carry;
            if(i>=0)  sum+=(x[i--]-'0');
            if(j>=0)  sum+=(y[j--]-'0');
            carry = sum/10;
            sum = sum%10;
            ans.push_back(sum+'0');
        }
        reverse(ans.begin(), ans.end());
        i = 0;
        while(i<ans.size() && ans[i]=='0') {
            i++;
        }
        return ans.substr(i);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
