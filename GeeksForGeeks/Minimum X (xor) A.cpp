//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int numB = count_num_of_set_bits(b);
        int numA = count_num_of_set_bits(a);
        int diff = numA - numB;
        while (diff > 0) {
            diff --;
            a &= (a - 1);
        }
        
        int i = 0;
        while (diff < 0) {
            if ((a & (1 << i)) == 0) {
                diff++;
                a |= (1 << i);
            }
            i++;
        }
        
        return a;
    } 
    
    private:
    int count_num_of_set_bits(int n) {
        int cnt = 0;
        while (n) {
            cnt ++;
            n &= (n - 1);
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
