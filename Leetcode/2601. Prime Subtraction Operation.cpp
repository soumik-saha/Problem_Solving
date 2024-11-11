class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> sieve(maxi+1, 1);
        for(int i=2; i<=maxi; i++) {
            int j = i;
            if(sieve[i])
                for(int j=i*i; j<maxi; j+=i) {
                    sieve[j] = 0;
                }
        }

        int last = 0;
        for(int i=0; i<=maxi; i++) {
            if(sieve[i]==0) {
                sieve[i] = last;
            }
            else {
                sieve[i] = i;
                last = i;
            }
        }

        int prev = -1;
        for(int i=0; i<n; i++) {
            int val = nums[i];
            for(int j=val-1; j>=2; j--) {
                if(val-sieve[j]>prev) {
                    nums[i] = val-sieve[j];
                    
                    break;
                }
            }
            prev = nums[i];
        }

        for(int i=1; i<n; i++) {
            if(nums[i]<=nums[i-1]) {
                return false;
            }
        }

        return true;
    }
};
