//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<int> stk;
    int minEle = INT_MAX;
    
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if(stk.empty()) {
            minEle = x;
        }
        else {
            if(x<=minEle) {
                stk.push(minEle);
                minEle = x;
            }
        }
        stk.push(x);
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!stk.empty()) {
            int temp = stk.top();
            stk.pop();
            if(temp==minEle && !stk.empty()) {
                minEle = stk.top();
                stk.pop();
            }
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(stk.empty()) return -1;
        return stk.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(stk.empty()) return -1;
        return minEle;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
