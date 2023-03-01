class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    void MergeSort(vector<int> &arr, int begin, int end) {
        if(begin>=end) {
            return;
        }

        auto mid = (begin+end)/2;
        MergeSort(arr, begin, mid);
        MergeSort(arr, mid+1, end);
        merge(arr, begin, mid, end);
    }
    void merge(vector<int> &arr, int begin, int mid, int end) {
        int i,j,k,n1=mid-begin+1,n2=end-mid;
        int L[n1], R[n2];

        for(i=0; i<n1; i++) {
            L[i] = arr[begin+i];
        }
        
        for(j=0; j<n2; j++) {
            R[j] = arr[mid+1+j];
        }

        i = 0;
        j = 0;
        k = begin;

        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k++] = L[i++];
            }
            else{
                arr[k++] = R[j++];
            }
        }

        while(i<n1){
            arr[k++] = L[i++];
        }

        while(j<n2){
            arr[k++] = R[j++];
        }
    }
};
