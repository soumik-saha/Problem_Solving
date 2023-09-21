class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> mp;
        for(int i=0; i<nums1.size(); i++) {
            mp.push(nums1[i]);
        }
        for(int i=0; i<nums2.size(); i++) {
            mp.push(nums2[i]);
        }
        vector<double> arr;
        while(!mp.empty()) {
            arr.push_back(mp.top());
            mp.pop();
        }

        int n = arr.size();
        if(n%2==0) {
            return (arr[n/2]+arr[n/2-1])/2;
        }
        else {
            return arr[n/2];
        }
    } 
};
