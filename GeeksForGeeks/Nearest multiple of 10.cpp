//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.size();
        if(str.back()<='5') {
            str.back() = '0';
        }
        else {
            str.back() = '0';
            bool  flag = false;
            for(int i=n-2; i>=0; i--) {
                if(str[i]!='9') {
                    str[i]++;
                    flag = true;
                    break;
                }
                else {
                    str[i] = '0';
                }
            }
            if(flag==false) {
                str = "1"+str;
            }
        }
        
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends
