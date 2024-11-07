//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(br.readLine().trim());

        while (testCases-- > 0) {
            String[] str = br.readLine().trim().split(" ");
            int[] arr = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                arr[i] = Integer.parseInt(str[i]);
            }

            Solution ob = new Solution();
            List<Integer> result = ob.findSplit(arr);

            if (result.get(0) == -1 && result.get(1) == -1) {
                System.out.println("false");
            } else {
                System.out.println("true");
            }
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    // Function to determine if array arr can be split into three equal sum sets.
    public List<Integer> findSplit(int[] arr) {
        int n = arr.length;
        List<Integer> ans = new ArrayList<Integer>();
        ans.add(-1);
        ans.add(-1);
        int left = 0, right = n-1;
        int lSum = 0, rSum = 0;
        List<Integer> prefSum = new ArrayList<Integer>();
        prefSum.add(arr[0]);
        for(int i=1; i<n; i++) {
            prefSum.add(prefSum.get(prefSum.size() - 1) + arr[i]);
        }
        while(left<right) {
            if(prefSum.get(left) == prefSum.get(n-1) - prefSum.get(right-1)) {
                if(prefSum.get(right-1) - prefSum.get(left) == prefSum.get(left)) {
                    ans.set(0, left);
                    ans.set(1, right-1);
                    
                    return ans;
                } else {
                    left++;
                    right--;
                }
            } else if(prefSum.get(left) < prefSum.get(n-1) - prefSum.get(right-1)) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
}
