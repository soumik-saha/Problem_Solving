//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Way 1: remove all a's first && Way 2: vice-versa
    char firstChar = str[0];
    int cnt = 1, flag = 1;
    for(int i=0; i<str.size(); i++) {
        if (firstChar==str[i])
            flag = 1;
        else {
            if(flag==1) {
                cnt++;
            }
            flag = 0;
        }
    }
    return cnt;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends
