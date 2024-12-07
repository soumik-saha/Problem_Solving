//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int merge(vector<int>& arr, int start, int mid, int end) {
        int left = start, right = mid+1;
        int count = 0;
        vector<int> temp;
        while(left<=mid && right<=end) {
            if(arr[left]<=arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                count += mid-left+1;
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid) {
            temp.push_back(arr[left++]);
        }
        while(right<=end) {
            temp.push_back(arr[right++]);
        }
        for(int i=start; i<=end; i++) {
            arr[i] = temp[i-start];
        }
        return count;
    }
    int mergeCount(vector<int>& arr, int start, int end) {
        if(start>=end)  return 0;
        int count = 0;
        int mid = start + (end-start)/2;
        count += mergeCount(arr, start, mid);
        count += mergeCount(arr, mid+1, end);
        count += merge(arr, start, mid, end);
        return count;
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        int ans = mergeCount(arr, 0, n-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
