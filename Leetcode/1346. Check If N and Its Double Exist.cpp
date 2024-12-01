class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st(arr.begin(), arr.end());
        int zero = 0;
        for(int i=0; i<n; i++) {
            if(arr[i]!=0 && st.find(2*arr[i])!=st.end()) {
                return true;
            }
            else if(arr[i]==0) {
                zero++;
                if(zero>1)
                    return true;
            }
        }
        return false;
    }
};
