//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str){
            
            // frequency array to track the frequency of elements
            
            int freq[26] = {0};
            
            // queue to track the elements of the stream with one frequency
            
            queue<char>que;
            
            string ans = "";
            
            for( int i = 0 ; i < str.length() ; i++)
            {
                freq[str[i]-'a']++;
                
                if( freq[str[i]-'a'] == 1)
                {
                    que.push(str[i]);
                }
                
                // remove all the element from the begining of queue which are having frequency greater than 1
                
                while(que.empty() == false && freq[que.front()-'a'] > 1)
                {
                    que.pop();
                }
                
                // if que is empty then append  # to answer otherwise append the character 
                
                if( que.empty())
                {
                    ans += "#";
                }
                else
                {
                    ans += que.front();
                }
            }
            
            // finally return the answer
            
            return ans;
        }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
