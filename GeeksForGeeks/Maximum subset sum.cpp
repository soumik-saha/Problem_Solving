//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long findMaxSubsetSum(int n, vector<int> &a) {
        // code here
        long long pre_taken = a[0], pre_not_taken = 0;
        for(int i=1;i<n;i++) {
            long long cur_taken = 1LL * a[i] + max(pre_taken,pre_not_taken);
            long long cur_not_taken = pre_taken;
            swap(cur_taken,pre_taken);
            swap(cur_not_taken,pre_not_taken);
        }
        return max(pre_taken, pre_not_taken);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
