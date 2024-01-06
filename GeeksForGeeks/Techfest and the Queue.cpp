//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int sumOfPowers(int a, int b) {
        vector<int> sieve(b + 1, 1);
        vector<int> primes;

        // Sieve of Eratosthenes to generate prime numbers up to 'b'
        for (int i = 2; i * i <= b; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= b; j += i) {
                    sieve[j] = 0;
                }
            }
        }

        for (int i = 2; i <= b; i++) {
            if (sieve[i])
                primes.push_back(i);
        }

        // Precompute cumulative sum of prime powers
        vector<int> primePowers(b + 1, 0);
        for (int prime : primes) {
            for (int j = prime; j <= b; j += prime) {
                int temp = j;
                while (temp % prime == 0) {
                    primePowers[j]++;
                    temp /= prime;
                }
            }
        }

        int totalPoints = 0;

        // Accumulate points using precomputed array
        for (int i = a; i <= b; i++) {
            totalPoints += primePowers[i];
        }

        return totalPoints;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
