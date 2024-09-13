class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = arr.size();
        vector<int> prefixXor(n,0);
        prefixXor[0] = arr[0];
        
        for(int i=1; i<n; i++) {
            prefixXor[i] = prefixXor[i-1] ^ arr[i];
        }

        for(auto q:queries) {
            if(q[0]==0) {
                ans.push_back(prefixXor[q[1]]);
            }
            else {
                ans.push_back(prefixXor[q[1]]^prefixXor[q[0]-1]);
            }
        }

        return ans;
    }
};
