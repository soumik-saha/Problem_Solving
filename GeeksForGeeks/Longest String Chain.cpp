//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        int n = words.size();
        sort(words.begin(), words.end(), [&](string a, string b) {
            return a.size()<b.size();
        });
        
        unordered_map<string, int> dp;
        int longest_chain = 1;
        
        for(string word:words) {
            dp[word] = 1;
            
            for(int i=0; i<word.size(); i++) {
                string prev_word = word.substr(0, i) + word.substr(i+1);
                
                if(dp.find(prev_word)!=dp.end()) {
                    dp[word] = max(dp[word], dp[prev_word]+1);
                }
            }
            
            longest_chain = max(longest_chain, dp[word]);
        }
        
        return longest_chain;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
