 int totalTime(int n, vector<int> &arr, vector<int> &time) {
        unordered_set<int> s;
        
      int ans = -1;
        
        for(int i=0;i<n;i++){
            if(s.find(arr[i]) != s.end()){
                ans += time[arr[i]-1];
            }
            else{
                ans++;
                s.insert(arr[i]);
            }
        }
        
        return ans;
    }
