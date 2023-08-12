class Solution
{
public:
    int binarySearch(vector<int>& tails, int low, int high, int key) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (tails[mid] >= key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    int longestSubsequence(int n, int a[])
    {
        if (n == 0) {
            return 0;
        }

        vector<int> tails(n, 0);
        int length = 1;
        tails[0] = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] < tails[0]) {
                tails[0] = a[i];
            } else if (a[i] > tails[length - 1]) {
                tails[length++] = a[i];
            } else {
                int pos = binarySearch(tails, 0, length - 1, a[i]);
                tails[pos] = a[i];
            }
        }

        return length;
    }
};
