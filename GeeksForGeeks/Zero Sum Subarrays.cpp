// Effective (O(N))
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        long long int ans=0, zero=0, presum=0;

        unordered_map<long long int, long long int>mpp;

        for(int i=0;i<n;i++){

            presum+=arr[i];
            if(presum==0) ans++;
            mpp[presum]++;

        }

        for(auto it:mpp) {

            long long int x=it.second;
            ans+= (x*(x-1))/2;

        }
        return ans;
    }
};

//-------------------------------------------------------------------------------
// Brute Force (TLE Error)
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        long long int cnt = 0, streak;
        for(int i=0; i<n; i++){
            streak = arr[i];
            if(arr[i]==0)
                cnt++;
            for(int j=i+1; j<n; j++){
                streak +=  arr[j];
                if(streak == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};
