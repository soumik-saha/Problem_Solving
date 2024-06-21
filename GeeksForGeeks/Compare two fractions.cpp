//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        string s1, x1, s2, x2;
        int i=0;
        for(; i<str.size(); i++) {
            if(str[i]=='/') {
                i++;
                break;
            }
            s1+=str[i];
        }
        for(; i<str.size(); i++) {
            if(str[i]==',') {
                i++;
                break;
            }
            x1+=str[i];
        }
        for(; i<str.size(); i++) {
            if(str[i]=='/') {
                i++;
                break;
            }
            s2+=str[i];
        }
        for(; i<str.size(); i++) {
            x2+=str[i];
        }
        
        double ss1 = stod(s1);
        double xx1 = stod(x1);
        double ss2 = stod(s2);
        double xx2 = stod(x2);
        
        if(ss1/xx1 > ss2/xx2) {
            return to_string(int(ss1))+"/"+to_string(int(xx1));
        }
        else if(ss1/xx1 < ss2/xx2) {
            return to_string(int(ss2))+"/"+to_string(int(xx2));
        }
        return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends
