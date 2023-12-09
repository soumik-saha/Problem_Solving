//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int smithNum(int n) {
        if(isPrime(n))
            return 0;
        
        return sumOfPrimeFactor(n) == sumOfDigits(n);
    }
    bool isPrime(int n) {
        if(n==1) {
            return false;
        }
        
        for(int i=2; i<n; i++) {
            if(n%i==0) {
                return false;
            }
        }
        
        return true;
    }
    int sumOfDigits(int n) {
        int sum = 0;
        while(n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int sumOfPrimeFactor(int n) {
        int f = 1;
        int sum = 0;
        while(n>1) {
            f++;
            if(!isPrime(f)) {
                continue;
            }
            
            while(n % f == 0)  {
                sum += sumOfDigits(f);
                n /= f;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
