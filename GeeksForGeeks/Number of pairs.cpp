class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        long long count = 0;
        long long n = arr.size();
        long long m = brr.size();
        
        unordered_map<int, int> mp1, mp2;
        for(int x:arr) {
            mp1[x]++;
        }
        for(int y:brr) {
            mp2[y]++;
        }
        
        for(auto &it1:mp1) {
            auto e1 = it1.first;
            auto f1 = it1.second;
            for(auto &it2:mp2) {
                auto e2 = it2.first;
                auto f2 = it2.second;
                
                if (e1 == e2) {
                    continue; 
                }
                
                double log1 = e2 * log(e1);
                double log2 = e1 * log(e2);
                
                if (log1 > log2) {
                    count = (count + f1 * f2);
                }
            }
        }
        
        return count;
    }
};
