//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& a, int n){

      int i=0;

      int j=1;

      long long int work=0;

      while(i<n){

          if((a[i]>0&&a[j]<0)||(a[i]<0&&a[j]>0)){

              if(abs(a[i])<abs(a[j])){

                  work=work+(j-i)*abs(a[i]);

                  a[j]=a[i]+a[j];

                  a[i]=0;

                  

                  i++;

                  

              }else if(abs(a[i])>abs(a[j])){

                  work=work+(j-i)*abs(a[j]);

                  a[i]=a[i]+a[j];

                  a[j]=0;

                  j++;

              }else{

                  work=work+abs(a[i])*(j-i);

                  a[i]=0;

                  a[j]=0;

                  i++;

                  j++;

              }

          }else if((a[i]>0&&a[j]>0)||(a[i]<0&&a[j]<0)){

              j++;

          }else if (a[i]==0||a[j]==0){

              if(a[i]==0){

                  i++;

              }

              if(a[j]==0){

                  j++;

              }

          }

          if(i==j){

              j++;

          }

      }

      return work;

  }
};
