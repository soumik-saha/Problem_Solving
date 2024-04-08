#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define mp make_pair
int mod = 998244353;
const int Highest = 1e7 + 10;
const int Max = 1e9 + 7;
const int Min = -100000;
 
//---------------------GCD----------------------//
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
//-------------------Modulo_Inverse-----------------------//
 
int mod_inv(int i)
{
    if (i == 1)
        return 1;
    return (mod - ((mod / i) * mod_inv(mod % i)) % mod) % mod;
}
 
//---------------Mod_Multiplication-------------------//
 
int mod_mul(int a, int b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
 
//-------------------Factorial------------------------//
 
int *fact;
void calFact()
{
    fact = new int[Highest];
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < Highest; i++)
        fact[i] = mod_mul(fact[i - 1], i);
}
 
//------------------------nCr--------------------------//
 
int ncr(int n, int r)
{
    int ans = fact[n];
    ans = mod_mul(ans, mod_inv(fact[n - r]));
    ans = mod_mul(ans, mod_inv(fact[r]));
    return ans;
}
 
//--------------is_Power_of_Two--------------------------//
 
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
 
//---------------is_Kth_Bit_set-------------------------//
 
bool isKthBitSet(int n, int k)
{
    if (n & (1 << (k - 1)))
        return true;
    return false;
}
 
//-------------------is_Prime------------------------------//
 
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
//-------------------Prime_Sieve--------------------------//
 
void primesieve()
{
    int sieve[Highest];
    sieve[0] = false;
    sieve[1] = false;
 
    for (int i = 2; i * i <= Highest; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= Highest; j += i)
                sieve[j] = false;
        }
    }
}
 
//-------------------Binary_Search--------------------------//
 
bool searching(vector<int> &v, int x, int index)
{
    int n = v.size();
    int start = index + 1;
    int end = n - 1;
 
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] <= x and v[mid] != v[index])
            return true;
        else if (v[mid] > x)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return false;
}
 
void removeChar(char *s, char c)
{
 
    int j, n = strlen(s);
    for (int i = j = 0; i < n; i++)
        if (s[i] != c)
            s[j++] = s[i];
 
    s[j] = '\0';
}
 
int isSubstring(string s1, string s2)
{
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}
 
int maxSum(int arr[], int n, int k)
{
    int res = 0;
    for (int i = 0; i < k; i++)
        res += arr[i];
 
    int curr_sum = res;
    for (int i = k; i < n; i++)
    {
        curr_sum += arr[i] - arr[i - k];
        res = max(res, curr_sum);
    }
 
    return res;
}
 
//---------------MAIN FUNCTION---------------------//
 
void solve()
{
    
    return;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
