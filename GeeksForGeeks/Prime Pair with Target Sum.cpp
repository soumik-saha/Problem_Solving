//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> getPrimes(int n) {
        // code here
        vector<int> res(2, -1);
        
        for(int i=2; i<=n; i++) {
            if(isPrime(i) && isPrime(n-i)) {
                res[1] = i;
                res[0] = n-i;
            }
        } 
        
        return res;
    }
    bool isPrime(int n) {
        if(n<=1)    return false;
        if(n<=3)    return true;
        
        if(n%2==0 || n%3==0) {
            return false;
        }
        
        for(int i=5; i*i<=n; i=i+6) {
            if(n%i==0 || n%(i+2)==0) {
                return false;
            }
        }
        
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends
