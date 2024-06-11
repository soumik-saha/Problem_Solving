//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<vector<long long>> diff(n,  vector<long long>(3, -1));
        
        for(int i=0; i<n; i++) {
            diff[i][0] = abs(arr[i]-brr[i]);
            diff[i][1] = arr[i];
            diff[i][2] = brr[i];
        }
    
        sort(diff.rbegin(), diff.rend());
        long long ans = 0;
        
        for(int i=0; i<n; i++) {
            if(x>0 && y>0) {
                if(diff[i][1]>=diff[i][2]) {
                    ans += diff[i][1];
                    x--;
                }
                else {
                    ans += diff[i][2];
                    y--;
                }
            }
            else if(y>0) {
                ans += diff[i][2];
                y--;
            }
            else if(x>0) {
                ans += diff[i][1];
                x--;
            }
        }
        
        return ans;
    }    
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends
