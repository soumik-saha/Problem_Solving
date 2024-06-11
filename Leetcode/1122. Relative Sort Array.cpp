class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxElement = *max_element(arr1.begin(), arr1.end());
        vector<int> count(maxElement+1, 0);

        for(int a:arr1) {
            count[a]++;
        }

        vector<int> ans;

        for(int a:arr2) {
            while(count[a]>0) {
                count[a]--;
                ans.push_back(a);
            }
        }

        for(int i=0; i<=maxElement; i++) {
            while(count[i]>0) {
                count[i]--;
                ans.push_back(i);
            }
        }

        return ans;
    }
};
