class Solution {
    public int circularSubarraySum(int arr[]) {
        int prefixSum = 0;
        int maxSum = Integer.MIN_VALUE;
        
        int sum = 0;
        for (int num : arr) {
            sum += num;
            prefixSum += num;
            maxSum = Math.max(maxSum, sum);
            sum = Math.max(sum, 0);
        }

        int currSum = 0;
        for (int num : arr) {
            currSum += num;
            currSum = Math.min(0, currSum);
            maxSum = Math.max(maxSum, prefixSum - currSum);
        }
        
        return maxSum;
    }
