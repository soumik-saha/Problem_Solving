//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void swap(long long *x,long long *y){
            int temp = *x;
            *x = *y;
            *y = temp;
        }
        void swapIfGreater(long long arr1[], long long arr2[],int i,int j){
            if(arr1[i]>arr2[j])
                swap(&arr1[i],&arr2[j]);
        }
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            long long len = n+m;
            long long gap = len/2 + len%2;
            while(gap){
                long long low = 0;
                long long high = gap;
                while(high<n+m){
                    if(high<n){
                        if(arr1[low]>arr1[high]){
                            int temp = arr1[low];
                            arr1[low] = arr1[high];
                            arr1[high] = temp;
                        }
                        
                    }
                    else if(low>=n){
                        if(arr2[low-n]>arr2[high-n]){
                            int temp = arr2[low-n];
                            arr2[low-n] = arr2[high-n];
                            arr2[high-n] = temp;
                        }
                    }
                    else{
                        if(arr1[low]>arr2[high-n]){
                            int temp = arr1[low];
                            arr1[low] = arr2[high-n];
                            arr2[high-n] = temp;
                        }
                    }
                    low++;
                    high++;
                }
                if(gap==1)
                    break;
                gap = gap/2 + gap%2;
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends
