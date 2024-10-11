vector<int> rearrange(const vector<int>& arr) {
        // Code here
        vector<int>v(arr.size(),-1);
           unordered_set<int> s(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++)
        {
         if(s.find(i)!=s.end())v[i]=i;
        }
        
           return v;
    }
