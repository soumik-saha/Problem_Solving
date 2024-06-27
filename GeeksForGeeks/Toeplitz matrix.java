//{ Driver Code Starts
import java.util.*;

class Check_IsToepliz {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T > 0) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int arr[][] = new int[N][M];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) arr[i][j] = sc.nextInt();
            }

            Solution g = new Solution();
            boolean b = g.isToepliz(arr);

            if (b == true)
                System.out.println("true");
            else
                System.out.println("false");

            T--;
        }
    }
}
// } Driver Code Ends


class Solution {
    /*You are required to complete this method*/
    boolean isToepliz(int mat[][]) {
        // Your code here
        int n = mat.length;
        int m = mat[0].length;
        
        for(int i=0; i<n; i++) {
            int x = i, y = 0;
            while(x<n && y<m)
                if(mat[x++][y++]!=mat[i][0])    return false;
        }
        
        for(int i=1; i<m; i++) {
            int x = i, y = 0;
            while(x<m && y<n)
                if(mat[y++][x++]!=mat[0][i])    return false;
        }
        
        return true;
    }
}
