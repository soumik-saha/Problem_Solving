class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        vector<int> v;
        for(int i=0;i<N;i++) {
            int n=v.size(),x=asteroids[i];
            if(n==0) {
                v.push_back(asteroids[i]);
            }
            else if(v[n-1]<0 || x>0) {
                v.push_back(asteroids[i]);
            }
            else if(v[n-1]+x==0) {
                v.pop_back();
            }
            else if(v[n-1]+x<0) {
                v.pop_back();
                i--;
            }
        }
        return v;
    }
};
