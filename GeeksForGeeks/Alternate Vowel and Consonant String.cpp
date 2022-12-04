// Brute-Force Method (TLE error)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string S, int N)
    {
        queue<char> vowels, consonant;
        vector<char> v, c;
        for(auto i : S){
            if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u')
                v.push_back(i);
            else
                c.push_back(i);
        }
        sort(v.begin(), v.end());
        sort(c.begin(), c.end());
        for(auto i=0; i<v.size();i++){
            vowels.push(v[i]);
        }
        for(auto i=0; i<c.size();i++){
            consonant.push(c[i]);
        }
        if(consonant.size()+1!=vowels.size() && consonant.size()!=vowels.size()+1 && consonant.size()!=vowels.size()){
            return "-1";
        } 
        else if(vowels.front() < consonant.front()){
            for(int i=0; i<N; i=i+2){
                if(vowels.size() >= consonant.size()){
                    if(vowels.size() && consonant.size()){
                        S[i]=vowels.front();
                        S[i+1]=consonant.front();
                        vowels.pop();
                        consonant.pop();
                    }
                    else if(vowels.size()){
                        S[i]=vowels.front();
                        vowels.pop();
                    }
                }
                else{
                    if(vowels.size() && consonant.size()){
                        S[i+1]=vowels.front();
                        S[i]=consonant.front();
                        vowels.pop();
                        consonant.pop();
                    }
                    else if(consonant.size()){
                        S[i]=consonant.front();
                        consonant.pop();
                    }
                }
            }
        }
        else{
            for(int i=0; i<N; i=i+2){
                if(vowels.size() >= consonant.size()){
                    if(vowels.size() && consonant.size()){
                        S[i+1]=vowels.front();
                        S[i]=consonant.front();
                        vowels.pop();
                        consonant.pop();
                    }
                    else if(consonant.size()){
                        S[i]=consonant.front();
                        consonant.pop();
                    }
                }
                else{
                    if(vowels.size() && consonant.size()){
                        S[i]=vowels.front();
                        S[i+1]=consonant.front();
                        vowels.pop();
                        consonant.pop();
                    }
                    else if(vowels.size()){
                        S[i]=vowels.front();
                        vowels.pop();
                    }
                }
            }
        }
        return S;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

//----------------------------------------------------

// Optimised Code

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string S, int N)
    {
        int nv=0,nc=0,t;
        vector<vector<int>> v(26,vector<int>(2,0));
        for(int i=0;i<N;i++) {
            char c=S[i];
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
                v[c-'a'][1]++;
                nv++;
            }
            else {
                v[c-'a'][0]++;
                nc++;
            }
        }
        if(nv-nc>1 || nc-nv>1) {
            return "-1";
        }
        if(nv>nc) {
            t=1;
        }
        else if(nc>nv) {
            t=0;
        }
        else {
            for(int i=0;i<26;i++) {
                if(v[i][0]>0) {
                    t=0;
                    break;
                }
                if(v[i][1]>0) {
                    t=1;
                    break;
                }
            }
        }
        S="";
        for(int i=0;i<N;i++) {
            for(int j=0;j<26;j++) {
                if(v[j][t]>0) {
                    v[j][t]--;
                    t^=1;
                    S+='a'+j;
                    break;
                }
            }
        }
        return S;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}

// } Driver Code Ends
