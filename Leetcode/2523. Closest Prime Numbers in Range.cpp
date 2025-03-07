class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int num1=-1, num2=-1;
        int difference = INT_MAX;

        vector<bool> sieve(right+1, true);
        sieve[0] = sieve[1] = false;

        for(int i=2; i*i<=right; i++) {
            if(sieve[i]) {
                for(int j=i*i; j<=right; j+=i) {
                    sieve[j] = false;
                }
            }
        }
        int x=-1, y=-1;
        while(left<=right) {
            if(sieve[left]) {
                if(num1==-1 && num2==-1) {
                    num1 = left;
                }
                else {
                    num2 = num1;
                    num1 = left;
                    cout<<num1<<" "<<num2<<endl;
                    if(abs(num1-num2)<difference){
                        x = num1;
                        y = num2;
                        difference = abs(num1-num2);
                    }
                }
            }
            left++;
        }

        if (x == -1 || y == -1) {
            return {-1, -1};
        }

        return {y, x};
    }
};
