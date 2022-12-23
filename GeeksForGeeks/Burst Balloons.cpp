class Solution {
public:
    int maxCoins(int N, vector<int> &arr) {
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return f(arr,0,N-1,dp);
    }
    
    int f(vector<int>& a,int i,int j,vector<vector<int>>& dp) {
      if(i>j) return 0;
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      int l1 = (i-1>=0 ? a[i-1]:1); 
      int r1 = (j+1<a.size() ? a[j+1]:1); 
      int ans=0;
      for(int k=i;k<=j;k++) {
          int left = f(a,i,k-1,dp);
          int right = f(a,k+1,j,dp);
          
          int coin = left+right+l1*a[k]*r1;
          
          ans = max(ans,coin);
      }
      
      return dp[i][j]=ans;
  }
};
