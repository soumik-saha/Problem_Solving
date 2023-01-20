//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
   int maxWeightCell(int n, vector<int> Edge)

  {

      int ans=0;

      int maxi=0;

      vector<int> degree(n,0);

      for(int i=0;i<n;i++)

      {

          int to=Edge[i];

          if(to!=-1)

          {

              degree[to]+=i;

              if(maxi<=degree[to])

              {

                  maxi=degree[to];

                  ans=to;

              }

          }

      }

      return ans;

  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends
