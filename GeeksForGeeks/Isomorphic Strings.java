//{ Driver Code Starts
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.*;


public class Driver {
    
    public static void main(String[] args)throws IOException {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while(tc-->0)
        {
            String s1 = br.readLine();
            String s2 = br.readLine();
            
            Solution obj = new Solution();
            
            boolean a = obj.areIsomorphic(s1,s2);
            if(a)
            System.out.println(1);
            else
            System.out.println(0);
        }
    }
    
}

// } Driver Code Ends


class Solution
{
    //Function to check if two strings are isomorphic.
    public static boolean areIsomorphic(String str1,String str2)
    {
        // Your code here
        int m = str1.length(), n = str2.length();
        
        if(m != n)  
            return false;
        
        int s1[] = new int[128], s2[] = new int[128];
        
        for(int i=0; i<m; i++) {
            char c1 = str1.charAt(i);
            char c2 = str2.charAt(i);
            if(s1[c1] != s2[c2])
                return false;
            s1[c1] = i+1;
            s2[c2] = i+1;
        }
        
        return true;
    }
}
