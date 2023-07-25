class Solution {
private:
    int binarySearch(vector<int>& arr, int start, int end) {
        if(start<=end) {
            int mid = (start+end)/2;
            if(start==end)
                return start;
            else if(arr[mid]>arr[mid+1])
                return binarySearch(arr, start, mid);
            else
                return binarySearch(arr, mid+1, end);
        }
        return -1;
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        return binarySearch(arr, 0, n-1);
    }
};
