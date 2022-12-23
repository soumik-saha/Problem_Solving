class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> temp;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            if(arr[i]==0 && i+1<n){
                for(int j=i+1; j<n; j++){
                    temp.push_back(arr[j]);
                }
                arr[++i] = 0;
                int j = i+1, k=0;
                while(j<n && k<temp.size()){
                    arr[j++] = temp[k++];
                }
                temp.clear();
            }
        }
    }
};
