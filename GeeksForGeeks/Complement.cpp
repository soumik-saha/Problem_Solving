class Solution{
 private:
   pair<int,int> maxsum(vector<int>&arr,int n){
       int sum=0;
       int max_sum=INT_MIN;
       int l=0,r=0,temp=0;//
       for(int i=0;i<n;i++){
           sum+=arr[i];
           //max_sum=max(sum,max_sum);
           //for simple just uncomment upper line 
           //no need of first if in 2nd if sum<0 update sum=0;
           if(sum>max_sum){
               r=i;
               max_sum=sum;
               l=temp;//if max_sum is updated it new subarry found 
               // so we have to update l 
           }
           if(sum<0){
               sum=0; 
               temp=i+1;//temp just telling start index of new subarry
           }
           
       }
       pair<int,int>p;
       p=make_pair(l,r);
       return p;
       //return max_sum simple kadne
   }
public:
   vector<int> findRange(string s, int n) {
       // code here
       vector<int>arr;
       int ocnt=0;
       vector<int>ans;
       
       for(int i=0;i<n;i++){
           if(s[i]=='0'){
               arr.push_back(1);
           }
           else{
               arr.push_back(-1);
               ocnt++;
           }
       }
       if( ocnt==n){
           vector<int>temp={-1};
           return temp;
       }
       pair<int,int>p=maxsum(arr,arr.size());//kadane algorithm
       
       
       ans.push_back(p.first+1);// +1 because our index start from zero
       //in problem index is start from 1
       ans.push_back(p.second+1);
       return ans;
   }
};
