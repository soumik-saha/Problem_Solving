class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        int n = tasks.size(), cnt = 0;
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[tasks[i]]++;
        }

        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(tasks[i]);
        }
        vector<int> v(st.begin(), st.end());
        sort(v.begin(), v.end());

        for(int i=0; i<mp.size(); i++){
            if(mp[v[i]]==1){
                return -1;
            }
        }

        for(int i=0; i<v.size(); i++){
            if(mp[v[i]]%3>=0){
                cnt += mp[v[i]]/3;
                if(mp[v[i]]%3!=0)
                    cnt++;
            }
        }
        return cnt;
    }
};
