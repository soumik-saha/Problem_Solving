//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int arr[] = new int[s.length];
            for (int i = 0; i < s.length; i++) {
                arr[i] = Integer.parseInt(s[i]);
            }

            int[] ans = new Solution().constructLowerArray(arr);
            for (int i = 0; i < arr.length; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    class Pair {
        int value;
        int index;
        int count;
        
        Pair(int value, int index) {
            this.value = value;
            this.index = index;
            this.count = 0;
        }
    }
    
    public int[] constructLowerArray(int[] a) {
        Pair[] arr = new Pair[a.length];
        for (int i = 0; i < a.length; i++) {
            arr[i] = new Pair(a[i], i);
        }
        
        mergeSort(arr, 0, a.length - 1);
        
        int[] result = new int[a.length];
        for (int i = 0; i < arr.length; i++) {
            result[arr[i].index] = arr[i].count;
        }
        
        return result;
    }
    
    private void mergeSort(Pair[] arr, int left, int right) {
        if (left >= right) {
            return;
        }
        
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    
    private void merge(Pair[] arr, int left, int mid, int right) {
        Pair[] temp = new Pair[right - left + 1];
        int i = left, j = mid + 1, k = 0;
        
        while (i <= mid && j <= right) {
            if (arr[i].value <= arr[j].value) {
                arr[i].count += (j - mid - 1);
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        
        while (i <= mid) {
            arr[i].count += (j - mid - 1);
            temp[k++] = arr[i++];
        }
        
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        
        for (i = left, k = 0; i <= right; i++, k++) {
            arr[i] = temp[k];
        }
    }
}

